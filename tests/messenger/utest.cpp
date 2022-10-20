#include <memory>
#include <fstream>

#include "mu_test.h"
#include "encryptionFactory.hpp"
#include "messengerFactory.hpp"
#include "senderFactory.hpp"
#include "messenger.hpp"
#include "ISender.hpp"


BEGIN_TEST(test_messenger_defined_by_configuration) 

using namespace messenger; 
    
    MessengerFactory messengerFact;  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_upper_encryptor_stdin_send_to_screen) 

using namespace messenger;        
    
    MessengerFactory mf;
    auto msg = mf.Get();
    msg->Send();
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_rot_k_stdin_send_to_screen)

    using namespace messenger;        
    
    MessengerFactory mf;
    auto msg = mf.Get();
    msg->Send();

    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_xor_stdin_send_to_screen)

    using namespace messenger;        
    
    MessengerFactory mf;
    auto msg = mf.Get();
    msg->Send();

    ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)

    TEST(test_messenger_defined_by_configuration)  //upper  
    // TEST(test_no_encryption_stdin_send_to_screen)     
    // TEST(test_upper_encryptor_stdin_send_to_screen)
    // TEST(test_xor_stdin_send_to_screen)
    // TEST(test_rot_k_stdin_send_to_screen)    
    // TEST(test_upper_encryptor_read_from_file_send_to_screen)

END_SUITE




