#include "TCPClientSocket.hpp"

namespace net {

Client::Client(const char* a_address, uint16_t a_port) 
: m_clientSocket()
{
    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(a_address);
    address.sin_port = htons(a_port);

    if(connect(m_clientSocket.m_socket, (struct sockaddr*)&address, sizeof(address)) < 0 ) {
        throw TCPSocketExceptions("connect() failed", "in client Ctor");
    } 
}

Client::Client(int a_socket)
: m_clientSocket(a_socket)
{}


} //net