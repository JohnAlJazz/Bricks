#ifndef MESSENGER_PROTOCOL_HPP
#define MESSENGER_PROTOCOL_HPP

#include <vector>
#include <string>
#include <memory>

#include "TCPClientSocket.hpp"

namespace messenger {

struct Protocol {

    std::vector<unsigned char> Pack(std::string& a_msg);
    std::string UnPack(std::unique_ptr<net::Client> a_client);

};

} //messenger


#endif //MESSENGER_PROTOCOL_HPP