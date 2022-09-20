#include "Event_detector.hpp"

namespace net {

EventDetector::EventDetector(AsyncServer& a_syncServer, IAcceptor* a_acceptor, Handler* a_handler) 
: m_clients(0, 0)
, m_asyncServer(a_syncServer)
, m_acceptor(a_acceptor)
, m_handler(a_handler)
{}



} //net