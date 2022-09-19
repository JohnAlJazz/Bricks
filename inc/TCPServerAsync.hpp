#ifndef TCP_SERVER_ASYNCHRONIZER_HPP
#define TCP_SERVER_ASYNCHRONIZER_HPP

#include "Socket.hpp"
#include "TCPClientSocket.hpp"
#include "TCPSocketExceptions.hpp"

#include <memory> /*unique_ptr*/

namespace net {

class AsyncServer {
public:

    AsyncServer(uint16_t a_port);
    AsyncServer(const AsyncServer&) = delete;
    AsyncServer& operator=(const AsyncServer&) = delete;
    ~AsyncServer() = default;    
    
    std::unique_ptr<Client> Accept();    

private:

    friend class Asynchronizer;
    Socket m_serverSocket;    
    struct sockaddr_in m_address;
};


} //net


#endif //TCP_SERVER_ASYNCHRONIZER_HPP