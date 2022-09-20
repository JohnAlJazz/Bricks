#include "epoll.hpp"
#include "TCPClientSocket.hpp"

namespace net {

void Epoll::SetEpoll() {

    m_epollFd = epoll_create1(0);
    if (m_epollFd == -1) {
        throw TCPSocketExceptions("epoll_create() failed", "in Asynchronizer Ctor");
    }       

    m_event.events = EPOLLIN;
    m_event.data.fd = m_asyncServer.GetSocket();
    if (epoll_ctl(m_epollFd, EPOLL_CTL_ADD, m_asyncServer.GetSocket(), &m_event) == -1) {
        throw TCPSocketExceptions("epoll_ctl() failed", "in Asynchronizer Ctor");
    } 
}


Epoll::Epoll(AsyncServer& a_syncServer, IAcceptor* a_iAccept, Handler* a_handler) 
: EventDetector(a_syncServer, a_iAccept, a_handler) 
, m_event()
, m_events()
, m_epollFd(0)
{
    SetEpoll();
}

static void PrintReceivedVec(const std::vector<int>& a_vec) {

    std::cout << "in server socket\n";
    for(auto e : a_vec) {
        std::cout << e << ", ";
    }
    std::cout << "\n";
}

void Epoll::AcceptConnections() {
    std::unique_ptr<Client> client;
    try {
        client = m_asyncServer.Accept();
    } catch(...) {
        return;        
    }
    if(!m_acceptor->DoAccept(&client)) {
        close(client->m_clientSocket.m_socket);
        return;
    }

    m_event.events = EPOLLIN;
    m_event.data.fd = client->m_clientSocket.m_socket;
    if (epoll_ctl(m_epollFd, EPOLL_CTL_ADD, client->m_clientSocket.m_socket, &m_event) == -1) {
        close(client->m_clientSocket.m_socket);
        return;
    } 

    m_clients[client->m_clientSocket.m_socket] = std::move(client);   
}


void Epoll::Run() {

    while(1) { 
        int nfds = epoll_wait(m_epollFd, m_events, 1000, -1);      
        if(nfds == -1) {
            throw TCPSocketExceptions("epoll_wait() failed", "in Asynchronizer Run()");
        }             
        for(int i = 0; i < nfds; ++i) {
            if(m_events[i].data.fd == m_asyncServer.GetSocket()) {                   
                AcceptConnections();                                       
            }
        }
    }
}


} //net