#include "server.hpp"



namespace net {

Server::Server(uint16_t a_port, in_addr_t a_address, int a_optVal) 
: m_serverSocket(a_port, a_address) 
, m_port(a_port)
, m_clientSocket(0)
 {
    if(bind(m_serverSocket.m_socket, (struct sockaddr*)(&m_serverSocket.m_address), sizeof(m_serverSocket.m_address)) < 0) {
        throw "bind fail";
    }
  
    if(setsockopt(m_serverSocket.m_socket, SOL_SOCKET, SO_REUSEADDR, &a_optVal, sizeof(a_optVal)) < 0) {
        throw "reuse fail";
    }
}

void Server::Listen() {
    if(listen(m_serverSocket.m_socket, 1021) == -1) {
        throw "listen fail";
    }
}

void Server::Accept() {
    int length = sizeof(m_serverSocket.m_address);
    m_clientSocket = accept(m_serverSocket.m_socket, (struct sockaddr*)(&m_serverSocket.m_address), (socklen_t*)&length);
    if (m_clientSocket < 0) {
        throw "acception failed";
    }     
}

// void Server::Recieve() {
//     char buffer[1024];
//     int readBytes = recv(m_clientSocket , buffer, sizeof(buffer), 0);
//     if( readBytes < 0 ) {
//         throw "recv fail";
//     }
//     std::cout << buffer;
// }

// void Server::Send(const char* a_str, size_t a_size) {
//     int sentBytes = send(m_clientSocket, a_str, a_size, 0);
//     if(sentBytes < 0)
//     {       
//         throw "send fail";
//     }
// }


} //net


