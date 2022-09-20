#include "mu_test.h"
#include "TCPClientSocket.hpp"
#include "TCPSocketExceptions.hpp"
#include "Socket.hpp"

#include <assert.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <errno.h>

std::vector<double> RandDoublesInitializer() {
    std::vector<double> doubleVector;
    for(size_t i = 0; i < 10000000; ++i) {
        double d = rand() % 10;
        doubleVector.push_back(d);
    }
    return doubleVector;
}

// BEGIN_TEST(client) 
//     using namespace net;
//     std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
//     Client client("127.0.0.1", 8080);    
//     client.Send(vec);    
//     ASSERT_PASS();
// END_TEST


BEGIN_TEST(random_double_test) 
    using namespace net;
    std::vector<double> vector = RandDoublesInitializer();
    try {   
        Client client("127.0.0.1", 8080);     
        client.Send(vector);
    } catch(const TCPSocketExceptions& e) {
        std::cout << e.what() << ", " << e.where();
    }     
    double sum = std::accumulate(vector.begin(), vector.end(), 0);
    std::cout << "\nsum of vector sent from TCP client: " << sum << '\n';      
    ASSERT_PASS();
END_TEST


// int main() {

//     using namespace net;
//     std::vector<double> vector = RandDoublesInitializer();
//     while(1){
//         try {   
//             Client client("127.0.0.1", 8080);     
//             client.Send(vector);
//             std::cout << "SUCCESS sent\n";
//             break;
//         } catch(const TCPSocketExceptions& e) {
//             if(errno != EAGAIN) {
//                 std::cout << e.what() << ", " << e.where();
//                 return 1;                
//             }
//             continue;
//         } 
//     }
//     double sum = std::accumulate(vector.begin(), vector.end(), 0);
//     std::cout << "\nsum of vector sent from TCP client: " << sum << '\n'; 
// }


BEGIN_SUITE(Its what you learn after you know it all that counts)
	// TEST(client) 
    TEST(random_double_test)  	
    		
END_SUITE