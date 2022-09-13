#include "mu_test.h"
#include "TCPClientSocket.hpp"
#include "Socket.hpp"

#include <assert.h>
#include <iostream>
#include <vector>

BEGIN_TEST(client) 
    using namespace net;
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    Client client("127.0.0.1", 8080);    
    client.Send(vec);
    // client. Receive();    
    
    ASSERT_PASS();
END_TEST





BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(client)   	
    		
END_SUITE