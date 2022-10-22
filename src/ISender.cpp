#include "ISender.hpp"
#include "TCPClientSocket.hpp"
#include "messengerProtocol.hpp"

#include <iostream>

namespace messenger {

SendToTCP::SendToTCP(std::string a_ip, uint16_t a_port) 
: m_ip(a_ip)
, m_port(a_port)
{}

void SendToTCP::Send(std::string& a_message) {
    
    net::Client c{m_ip.c_str(), m_port};
    Protocol protocol;
    auto msg = protocol.Pack(a_message);    
    c.Send(msg);
}

} //messenger