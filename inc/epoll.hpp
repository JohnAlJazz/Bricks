#ifndef EPOLL_HPP
#define EPOLL_HPP

#include "Event_detector.hpp"
#include "TCPServerAsync.hpp"
#include "IAcceptor.hpp"
#include "Handler.hpp"
#include "TCPSocketExceptions.hpp"

#include <sys/epoll.h>
#include <vector>

namespace net {


class Epoll : public EventDetector {
public:

    Epoll(AsyncServer& a_syncServer, IAcceptor* a_iAccept, Handler* a_handler);
     
    void Run() override;

private:

    void AcceptConnections();
    void SetEpoll();

private:

    struct epoll_event m_event;
    struct epoll_event m_events[1000];
    int m_epollFd;
};


} //net

#endif //EPOLL_HPP
