#include <memory>
#include <fstream>

#include "messengerFactory.hpp"
#include "messenger.hpp"

using namespace messenger; 

#ifndef THE_TEST

int main(int argc, char* argv[]) { 

    std::fstream newFile;
    newFile.open("cmd", std::ofstream::out | std::ofstream::trunc);    
    std::string args;

    for(int i = 1; i < argc; ++i) {
        args = argv[i];
        if(i < argc - 1) {
            args += " ";
        }               
        newFile << args;               
    }       
    newFile.close();
    newFile.open("cmd");
    
    Configuration conf(newFile);
    MessengerFactory mf(conf);
    auto msg = mf.Get();
    msg->Send();       
}

#else

#include "mu_test.h"

using namespace messenger;

BEGIN_TEST(test_messenger_wrong_conf_file) //throws a run_time error 

    try {
        std::fstream file("blah");
        Configuration conf(file);
        MessengerFactory messengerFact(conf);  
        auto msg = messengerFact.Get();     
        msg->Send(); 
    }
    catch(const std::runtime_error& e) {
        std::cout << e.what() << '\n';
    }
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_messenger_UPPER_configuration) 
    
    std::fstream file("upper_config.txt");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_messenger_Rot13_configuration) 
    
    std::fstream file("rot13_config.txt");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_xor42_to_screen)           
    
    std::fstream file("xor42");
    Configuration conf(file);
    MessengerFactory mf(conf);
    auto msg = mf.Get();
    msg->Send();

    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_messenger_upper_from_file_to_screen) 
    
    std::fstream file("ff.txt");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_messenger_upper_write_to_file) 
    
    std::fstream file("upperToFile.txt");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_messenger_upper_file_to_file) 
    
    std::fstream file("file_to_file");
    Configuration conf(file);
    MessengerFactory messengerFact(conf);  
    auto msg = messengerFact.Get();     
    msg->Send();   
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_multi_to_screen)           
    
    std::fstream file("multi");
    Configuration conf(file);
    MessengerFactory mf(conf);
    auto msg = mf.Get();
    msg->Send();

    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_screen_to_tcp)           
    
    std::fstream file("toTcp");
    Configuration conf(file);
    MessengerFactory mf(conf);
    auto msg = mf.Get();
    msg->Send();

    ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)

    // TEST(test_messenger_wrong_conf_file)
    // TEST(test_messenger_UPPER_configuration)
    // TEST(test_messenger_Rot13_configuration)  
    // TEST(test_xor42_to_screen) 
    // TEST(test_messenger_upper_from_file_to_screen)
    // TEST(test_messenger_upper_write_to_file)
    // TEST(test_messenger_upper_file_to_file)
    // TEST(test_multi_to_screen) 
    TEST(test_screen_to_tcp)   

END_SUITE

#endif



