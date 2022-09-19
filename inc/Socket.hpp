#ifndef SOCKET_HPP__
#define SOCKET_HPP__

#include <sys/socket.h>
#include "unistd.h"
#include <arpa/inet.h>
#include <cstring>
#include <iostream>

#include "TCPSocketExceptions.hpp"


namespace net {   

class Socket {
public:

    Socket();
    Socket(int a_socket);    
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;
    ~Socket();       

private:

    friend class AsyncServer;
    friend class Asynchronizer;
    friend class Client;     
    int m_socket;    
};


#include "inl/Socket.hxx"


} //net



#endif //SOCKET_HPP__