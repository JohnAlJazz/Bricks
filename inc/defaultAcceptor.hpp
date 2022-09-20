#ifndef DEFAULT_ACCEPTOR_HPP
#define DEFAULT_ACCEPTOR_HPP

#include "IAcceptor.hpp"
#include "TCPClientSocket.hpp"


namespace net {

class DefaultAcceptor : public IAcceptor {
public:

    bool DoAccept(std::unique_ptr<Client>*) override;

};

#include "inl/defaultAcceptor.hxx"

} //net


#endif //DEFAULT_ACCEPTOR