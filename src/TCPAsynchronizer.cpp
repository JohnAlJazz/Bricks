#include "TCPAsynchronizer.hpp"
#include "TCPServerAsync.hpp"
#include "Socket.hpp"

#include <sys/epoll.h>
#include <memory>
#include <vector>
#include <numeric>
#include <fcntl.h>

namespace net {

void Asynchronizer::SetEpoll() {

    m_epollFd = epoll_create1(0);
    if (m_epollFd == -1) {
        throw TCPSocketExceptions("epoll_create() failed", "in Asynchronizer Ctor");
    }       

    m_event.events = EPOLLIN;
    m_event.data.fd = m_server.m_serverSocket.m_socket;
    if (epoll_ctl(m_epollFd, EPOLL_CTL_ADD, m_server.m_serverSocket.m_socket, &m_event) == -1) {
        throw TCPSocketExceptions("epoll_ctl() failed", "in Asynchronizer Ctor");
    } 
}

Asynchronizer::Asynchronizer(uint16_t a_port)
: m_server(a_port)
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

void Asynchronizer::AcceptConnections() {
    std::unique_ptr<Client> client = m_server.Accept();
    std::vector<int> iVector = client->Receive<std::vector<int>>();     
    
    PrintReceivedVec(iVector);    
    client->Send(iVector); 
}

void Asynchronizer::Run() {      
    
    while(1) { 
        int nfds = epoll_wait(m_epollFd, m_events, 1000, -1);      
        if(nfds == -1) {
            throw TCPSocketExceptions("epoll_wait() failed", "in Asynchronizer Run()");
        }             
        for(int i = 0; i < nfds; ++i) {
            if(m_events[i].data.fd == m_server.m_serverSocket.m_socket) {                   
                AcceptConnections();                         
            }
        }
    }
}


} //net


















// m_event.data.fd = client->m_clientSocket.m_socket;
    // m_event.events = EPOLLIN | EPOLLET;
    // if(epoll_ctl(m_epollFd, EPOLL_CTL_ADD, client->m_clientSocket.m_socket, &m_event) == -1) {
    //     throw TCPSocketExceptions("epoll_ctl() failed", "in Asynchronizer AcceptConnections()");
    // }
