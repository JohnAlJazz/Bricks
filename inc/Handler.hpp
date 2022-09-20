#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "TCPClientSocket.hpp"

namespace net {

class Handler {
public:

    virtual void HandleClientIncoming(std::unique_ptr<Client> a_client) = 0;

};


}//net


#endif //HANDLER