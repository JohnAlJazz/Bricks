#include "mu_test.h"

#include "TCPServerAsync.hpp"
#include "TCPClientSocket.hpp"
#include "TCPAsynchronizer.hpp"
#include "TCPSocketExceptions.hpp"
#include "Socket.hpp"

#include <assert.h>
#include <iostream>
#include <vector>


void PrintReceivedVec(const std::vector<int>& a_vec) {

    std::cout << "in client socket\n";
    for(auto e : a_vec) {
        std::cout << e << ", ";
    }
    std::cout << "\n";
}

BEGIN_TEST(async) 
    using namespace net;  
    Client client("127.0.0.1", 8080), client2("127.0.0.1", 8080), client3("127.0.0.1", 8080);
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    while(1) {        
        try {
            client.Send(vec);
            std::vector<int> v1 = client.Receive<std::vector<int>>();
            client2.Send(vec);
            std::vector<int> v2 = client2.Receive<std::vector<int>>();
            client3.Send(vec);       
            std::vector<int> v3 = client3.Receive<std::vector<int>>();
            
            PrintReceivedVec(v1);
            PrintReceivedVec(v2);
            PrintReceivedVec(v3);            
                       
        }catch(const TCPSocketExceptions &e) {
            std::cout << e.what() << ", " << e.where();
        }
    }       
    ASSERT_PASS();
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts) 	
    TEST(async)
    		
END_SUITE