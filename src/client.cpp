#include "client.hpp"


namespace net {

Client::Client(uint16_t a_port, const char* a_address) 
: m_clientSocket(a_port, inet_addr(a_address))
{}

void Client::Connect() {
    if(connect(m_clientSocket.m_socket, (struct sockaddr*)(&m_clientSocket.m_address), sizeof(m_clientSocket.m_address)) < 0 ) {
        throw "connect failed";
    }
}

void Client::Send(const char* a_str, size_t a_size) {
    int sentBytes = send(m_clientSocket.m_socket, a_str, a_size, 0);
    if(sentBytes < 0)
    {       
        throw "send fail";
    }
}

void Client::Receive() {
    char buffer[1024];
    int readBytes = recv(m_clientSocket.m_socket, buffer, sizeof(buffer), 0);
    if( readBytes < 0 ) {
        throw "recv fail";
    }
    std::cout << buffer;
}


} //net