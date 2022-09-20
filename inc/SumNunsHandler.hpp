#ifndef SUM_NUMS_HANDLER_HPP
#define SUM_NUMS_HANDLER_HPP

#include "Handler.hpp"
#include "TCPClientSocket.hpp"

#include <memory>

namespace net {

class SumNumsHandler : public Handler {
public:

    void HandleClientIncoming(std::unique_ptr<Client> a_client) override;

};


} //net

#endif //SUM_NUMS_HANDLER_HPP