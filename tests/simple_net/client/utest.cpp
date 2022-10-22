#include <assert.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <errno.h>
#include <memory>

#include "TCPClientSocket.hpp"
#include "TCPSocketExceptions.hpp"
#include "Socket.hpp"
#include "TcpProtocol.hpp"


int main() {
    using namespace net;   

    std::unique_ptr<Client> client{new Client("127.0.0.1", 8080)};
    std::vector<double> dVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<unsigned char> uscVec, uscVec2;
    Protocol protocol;
    uscVec = protocol.Pack(dVec);        
    client->Send(uscVec);
    uscVec2 = client->Receive();
    protocol.UnPack(client);

}

