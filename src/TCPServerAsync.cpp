#include "TCPServerAsync.hpp"

#include <fcntl.h> //set to non blocking?

namespace net {

AsyncServer::AsyncServer(uint16_t a_port) 
: m_serverSocket() 
, m_address()
 {
    memset(&m_address, 0, sizeof(m_address));
    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons(a_port);

    int optVal = 1;
    if(setsockopt(m_serverSocket.m_socket, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal)) < 0) {
        throw TCPSocketExceptions("setsockopt failed", "Async Ctor");
    }


    if(bind(m_serverSocket.m_socket, (struct sockaddr*)&m_address, sizeof(m_address)) < 0) {
        throw TCPSocketExceptions("bind failed", "Async Ctor");
    } 

    if(listen(m_serverSocket.m_socket, 1021) == -1) {
        throw TCPSocketExceptions("listen failed", "Async Ctor");
    }    
}

std::unique_ptr<Client> AsyncServer::Accept() {
    int length = sizeof(m_address);
    int clientSocket = accept(m_serverSocket.m_socket, (struct sockaddr*)(&m_address), (socklen_t*)&length);

    if (clientSocket < 0) {
        throw TCPSocketExceptions("accept() failed", "in server Accept");
    }  
    return std::unique_ptr<Client>{new Client{clientSocket}};   
}


}//net

	

