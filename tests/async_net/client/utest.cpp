#include "mu_test.h"

#include "TCPServerAsync.hpp"
#include "TCPClientSocket.hpp"
#include "TCPAsynchronizer.hpp"
#include "TCPSocketExceptions.hpp"
#include "Socket.hpp"

#include "Event_detector.hpp"
#include "defaultAcceptor.hpp"
#include "SumNunsHandler.hpp"
#include "epoll.hpp"

#include <assert.h>
#include <iostream>
#include <vector>


void PrintReceivedVec(const std::vector<int>& a_vec) {

    std::cout << "in client socket\n";
    for(auto e : a_vec) {
        std::cout << e << ", g";
    }
    std::cout << "\n";
}

// BEGIN_TEST(async) 
//     using namespace net;  
//     Client client("127.0.0.1", 8080);
//     std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
//     while(1) {        
//         try {
//             client.Send(vec);
//             std::vector<int> v1 = client.Receive<std::vector<int>>();          
            
//             PrintReceivedVec(v1);                      
                       
//         }catch(const TCPSocketExceptions &e) {
//             std::cout << e.what() << ", " << e.where();
//         }
//     }       
//     ASSERT_PASS();
// END_TEST

BEGIN_TEST(async) 
    using namespace net;  
    AsyncServer server(8080);
    DefaultAcceptor dAcceptor;
    SumNumsHandler Summer;
    Epoll ep(server, &dAcceptor, &Summer);
    
    
           
    ASSERT_PASS();
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts) 	
    TEST(async)
    		
END_SUITE