#ifndef SOCKET_H__
#define SOCKET_H__

#include <sys/socket.h>
#include "unistd.h"
#include <arpa/inet.h>
#include <cstring>
#include <iostream>

namespace net {

    

class Socket {
public:

    friend class Server;
    friend class Client;    
   

    Socket(uint16_t a_port, in_addr_t a_address);
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;
    ~Socket();       

private:
    int m_socket;
    struct sockaddr_in m_address; 
};

#include "inl/Socket.hxx"


} //net



#endif //SOCKET_H__