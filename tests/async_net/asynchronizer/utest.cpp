#include "mu_test.h"
#include "TCPServerAsync.hpp"
#include "TCPAsynchronizer.hpp"
#include "TCPSocketExceptions.hpp"
#include "Socket.hpp"

#include <assert.h>
#include <iostream>


BEGIN_TEST(async) 
    using namespace net;
    Asynchronizer async(8080);    
      
    try {
        async.Run();        
    }
    catch(const TCPSocketExceptions& e) {
        std::cout << e.what() << ", " << e.where();
    }
  
    ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
		
    TEST(async)    		

END_SUITE