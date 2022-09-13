#include "mu_test.h"
#include "TCPServerSocket.hpp"
#include "Socket.hpp"
#include "TCPClientSocket.hpp"

#include <assert.h>
#include <iostream>
#include <vector>
#include <memory>
#include <numeric>


BEGIN_TEST(server) 
    using namespace net;
    Server server(8080);
    std::vector<int> vec;    
    server.Listen();    
    std::unique_ptr<Client> client = server.Accept(); 
    vec = client->Receive<std::vector<int>>(); 
    for(auto e : vec) {
        std::cout << e << '\n';
    }  
    ASSERT_PASS();
END_TEST


BEGIN_TEST(large_vec_test) 
    using namespace net;
    Server server(8080);
    std::vector<double> v;    
    server.Listen();    
    std::unique_ptr<Client> client = server.Accept(); 
    v = client->Receive<std::vector<double>>(); 
    double sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "sum of vector accepted from TCP server: " << sum << '\n';  
    ASSERT_PASS();
END_TEST



BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(server)
    TEST(large_vec_test)    		
END_SUITE