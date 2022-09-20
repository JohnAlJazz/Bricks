#ifndef EVENT_DETECTOR_HPP
#define EVENT_DETECTOR_HPP

#include "IAcceptor.hpp"
#include "Event_detector.hpp"
#include "Handler.hpp"
#include "TCPClientSocket.hpp"
#include "TCPServerAsync.hpp"

#include <map>
#include <memory>


namespace net {

class EventDetector {
public:

    EventDetector(AsyncServer& a_syncServer, IAcceptor* a_acceptor, Handler* a_handler);

    virtual void Run() = 0;

protected:

    std::map<int, std::unique_ptr<Client>> m_clients;
    AsyncServer& m_asyncServer;
    IAcceptor* m_acceptor;
    Handler* m_handler;

};


} //net

#endif //EVENT_DETECTOR_HPP
