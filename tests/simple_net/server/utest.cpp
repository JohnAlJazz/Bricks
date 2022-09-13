#include "mu_test.h"
#include "server.hpp"
#include "Socket.hpp"

#include <assert.h>
#include <iostream>


BEGIN_TEST(server) 
    using namespace net;
    Server server(8080, INADDR_ANY, 1);
    server.Listen();
    server.Accept();
    server.Recieve();
    server.Send("Hi from server", 15);
    ASSERT_PASS();
END_TEST




BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(server)
    	
    		
END_SUITE