#include "Socket.hpp"


namespace net {

Socket::Socket() 
: m_socket(socket(AF_INET, SOCK_STREAM, 0)) {

    if(m_socket == -1) {
        throw "couldn't create a socket";
    }    
}

Socket::Socket(int a_socket) 
: m_socket(a_socket)
{}


Socket::~Socket() {
    close(m_socket);
}


} //net