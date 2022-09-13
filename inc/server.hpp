#ifndef SERVER_H__
#define SERVER_H__

#include "Socket.hpp"
#include <iostream>

namespace net {

class Server {
public:
    Server(uint16_t a_port, in_addr_t a_address, int a_optVal);
    Server(const Server&) = delete;
    Server& operator=(const Server&) = delete;
    ~Server() = default;

    void Listen();
    void Accept(); 

    template <typename T>
    T Receive();

    template <typename T>
    void Send(T* a_buffer);

private:
    Socket m_serverSocket;
    uint16_t m_port;
    int m_clientSocket;
};

#include "inl/server.hxx"

    
} //net

#endif //SERVER_H__