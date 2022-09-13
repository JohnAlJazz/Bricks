#ifndef CLIENT_HPP__
#define CLIENT_HPP__

#include <string>

#include "Socket.hpp"

namespace net {

class Client {
public:
    Client(const char* a_address, uint16_t a_port);
    Client(int a_socket);
    // Client(const Socket&) = default;
    Client& operator=(const Socket&) = delete;
    ~Client() = default;
  
    template <typename T>
    T Receive();

    template <typename T>
    void Send(T& a_buff);   

private:
    Socket m_clientSocket;
};

#include "inl/client.hxx"

    
} //net

#endif //CLIENT_HPP__