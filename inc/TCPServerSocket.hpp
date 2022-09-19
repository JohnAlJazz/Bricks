#ifndef SERVER_H__
#define SERVER_H__

#include "Socket.hpp"
#include "TCPClientSocket.hpp"
#include "TCPSocketExceptions.hpp"

#include <iostream>
#include <memory>

namespace net {

class Server {
public:

    Server(uint16_t a_port);
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    ~Server() = default;

    void Listen();
    std::unique_ptr<Client> Accept();    

private:

    friend class Asynchronizer;
    Socket m_serverSocket;    
    struct sockaddr_in m_address;
};

#include "inl/server.hxx"

    
} //net

#endif //SERVER_H__