#include "Socket.hpp"


namespace net {

Socket::Socket(uint16_t a_port, in_addr_t a_address) 
: m_socket(socket(AF_INET, SOCK_STREAM, 0)) {

    if(m_socket == -1) {
        throw "couldn't create a socket";
    }
    memset(&m_address, 0, sizeof(m_address));

    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = a_address;
    m_address.sin_port = htons(a_port);
}

Socket::~Socket() {
    close(m_socket);
}


} //net