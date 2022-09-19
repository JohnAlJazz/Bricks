#ifndef CLIENT_HPP__
#define CLIENT_HPP__

#include "Socket.hpp"
#include "TCPSocketExceptions.hpp"

namespace net {

class Client {
public:

    Client(const char* a_address, uint16_t a_port);
    Client(int a_socket);
    Client(const Socket&) = delete;
    Client& operator=(const Socket&) = delete;
    ~Client() = default;
  
    template <typename T>
    T Receive();

    template <typename T>
    void Send(T& a_buff);   

private:

    friend class Asynchronizer; 
    Socket m_clientSocket;
};

#include "inl/client.hxx"
    
} //net

#endif //CLIENT_HPP__