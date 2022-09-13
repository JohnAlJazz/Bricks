#include "mu_test.h"
#include "TCPClientSocket.hpp"
#include "Socket.hpp"

#include <assert.h>
#include <iostream>
#include <vector>
#include <numeric>

std::vector<double> RandDoubleInitializer() {
    std::vector<double> doubleVector;
    for(size_t i = 0; i < 1000; ++i) {
        double d = rand() % 10;
        doubleVector.push_back(d);
    }
    return doubleVector;
}


BEGIN_TEST(client) 
    using namespace net;
    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    Client client("127.0.0.1", 8080);    
    client.Send(vec);    
    ASSERT_PASS();
END_TEST

BEGIN_TEST(random_double_test) 
    using namespace net;
    std::vector<double> vector = RandDoubleInitializer();
    double sum = std::accumulate(vector.begin(), vector.end(), 0);
    Client client("127.0.0.1", 8080);    
    client.Send(vector);
    std::cout << "sum of vector sent from TCP client: " << sum << '\n';      
    ASSERT_PASS();
END_TEST




BEGIN_SUITE(Its what you learn after you know it all that counts)
	TEST(client) 
    TEST(random_double_test)  	
    		
END_SUITE