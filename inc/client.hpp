#ifndef CLIENT_H__
#define CLIENT_H__

#include <string>

#include "Socket.hpp"

namespace net {

class Client {
public:
    Client(uint16_t a_port, const char* a_address);
    Client(const Socket&) = delete;
    Client& operator=(const Socket&) = delete;
    ~Client() = default;

    void Connect();   
    void Send(const char* a_str, size_t a_size);
    void Send(const char* a_str, size_t a_size);
    void Receive();




private:
    Socket m_clientSocket;
};

    
} //net

#endif //CLIENT_H__