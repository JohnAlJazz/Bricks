#ifndef TCP_ASYNCHRONIZER_HPP
#define TCP_ASYNCHRONIZER_HPP

#include "TCPServerAsync.hpp"
#include "TCPClientSocket.hpp"
#include "TCPSocketExceptions.hpp"
#include "Socket.hpp"

#include <sys/epoll.h>

namespace net {

class Asynchronizer {
public:

    Asynchronizer(uint16_t a_port);
    ~Asynchronizer() = default;
    Asynchronizer(const Asynchronizer&) = delete;
    Asynchronizer& operator=(const Asynchronizer&) = delete;

    void Run();  

private:

    void SetEpoll();
    void AcceptConnections();

private:

    AsyncServer m_server;
    struct epoll_event m_event;
    struct epoll_event m_events[1000];
    int m_epollFd;
};

} //net


#endif //TCP_ASYNCHRONIZER_HPP