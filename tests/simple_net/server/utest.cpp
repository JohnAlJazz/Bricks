#include "mu_test.h"
#include "TCPServerSocket.hpp"
#include "Socket.hpp"
#include "TCPClientSocket.hpp"

#include <assert.h>
#include <iostream>
#include <vector>
#include <memory>


BEGIN_TEST(server) 
    using namespace net;
    Server server(8080);
    std::vector<int> v;    
    server.Listen();    
    std::unique_ptr<Client> client = server.Accept(); 
    v = client->Receive<std::vector<int>>(); 
    for(auto e : v) {
        std::cout << e << '\n';
    }  
    ASSERT_PASS();
END_TEST




BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(server)
    	
    		
END_SUITE