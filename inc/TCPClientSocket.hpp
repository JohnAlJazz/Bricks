#ifndef CLIENT_HPP__
#define CLIENT_HPP__

#include "Socket.hpp"
#include "TCPSocketExceptions.hpp"
#include <vector>

namespace net {

class Client {
public:

    Client(const char* a_address, uint16_t a_port);
    Client(int a_socket);
    Client(const Socket&) = delete;
    Client& operator=(const Socket&) = delete;
    ~Client() = default;  
    
    std::vector<unsigned char> Receive();
    
    void Send(std::vector<unsigned char>& a_buffer);   

private:

    friend class Asynchronizer; 
    friend class Epoll;
    Socket m_clientSocket;
};

#include "inl/client.hxx"
    
} //net

#endif //CLIENT_HPP__