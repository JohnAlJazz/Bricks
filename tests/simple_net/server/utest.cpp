#include "mu_test.h"
#include "TCPServerSocket.hpp"
#include "Socket.hpp"
#include "TCPClientSocket.hpp"

#include <assert.h>
#include <iostream>
#include <vector>
#include <memory>
#include <numeric>
#include <errno.h>


BEGIN_TEST(server) 
    using namespace net;
    Server server(8080);
    std::vector<int> vec;          
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
    std::unique_ptr<Client> client = server.Accept(); 
    v = client->Receive<std::vector<double>>(); 
    double sum = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "sum of vector received from TCP server: " << sum << '\n'; 

    ASSERT_PASS();
END_TEST

// int main() {
//     using namespace net;
//     Server server(8080);

//     std::vector<double> v;       
//     std::unique_ptr<Client> client = server.Accept(); 
//     while(1){
//         try{
//             v = client->Receive<std::vector<double>>(); 
//             break;
//         }
//         catch(const TCPSocketExceptions& e){
//             if(errno != EAGAIN) {
//                 std::cout << e.what() << ", " << e.where();
//                 return 1;
//             }
//             continue;
//         }
//     }
//     double sum = std::accumulate(v.begin(), v.end(), 0);
//     std::cout << "sum of vector received from TCP server: " << sum << '\n'; 
// }



BEGIN_SUITE(Its what you learn after you know it all that counts)
	// TEST(server)
    TEST(large_vec_test)    		
END_SUITE