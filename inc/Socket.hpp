#ifndef SOCKET_HPP__
#define SOCKET_HPP__

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

    Socket();
    Socket(int a_socket);    
    Socket(const Socket&) = delete;
    Socket& operator=(const Socket&) = delete;
    ~Socket();       

private:
    int m_socket;    
};

#include "inl/Socket.hxx"


} //net



#endif //SOCKET_HPP__