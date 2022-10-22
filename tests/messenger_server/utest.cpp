#include "mu_test.h"

#include "Socket.hpp"
#include "TCPClientSocket.hpp"
#include "TCPServerSocket.hpp"
#include "messengerProtocol.hpp"

#include <iostream>

using namespace net;
using namespace messenger;

BEGIN_TEST(test_messenger_to_TCP) 

    Server server(8080);                  
    Protocol protocol;
    while(true) {
        std::unique_ptr<Client> client = server.Accept(); 
        auto msg = protocol.UnPack(std::move(client));          

        std::cout << msg << '\n';  
    }
    
    ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
    TEST(test_messenger_to_TCP)    

END_SUITE