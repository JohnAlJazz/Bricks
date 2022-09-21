#ifndef PROTOCOL_HPP
#define PROTOCOL_HPP

#include <vector>
#include <memory>

#include "TCPClientSocket.hpp"

namespace net {

class Protocol {
public:

    Protocol() = default;
    ~Protocol() = default;
    Protocol(const Protocol&) = default;
    Protocol& operator =(const Protocol&) = default;

    std::vector<unsigned char> Pack(const std::vector<double>& a_vec);
    std::vector<double> UnPack(std::unique_ptr<Client>& a_client);

};

} //net

#endif //PROTOCOL_HPP