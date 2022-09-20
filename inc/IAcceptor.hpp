#ifndef I_ACCEPTOR_HPP
#define I_ACCEPTOR_HPP

#include "TCPClientSocket.hpp"

#include <memory> /*unique_ptr*/

namespace net {

class IAcceptor {
public:

    virtual bool DoAccept(std::unique_ptr<Client>*) = 0 ;

};

} //net




#endif// I_ACCEPTOR_HPP