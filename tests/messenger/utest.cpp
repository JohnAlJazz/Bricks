#include <memory>
#include <fstream>

#include "mu_test.h"
#include "encryptionFactory.hpp"
#include "senderFactory.hpp"
#include "messenger.hpp"
#include "ISender.hpp"


BEGIN_TEST(test_no_encryption_stdin_send_to_screen) 

using namespace messenger; 

    EncryptionFactory encryptionFact;
    SenderFactory senderFact;
    auto noEncryption = encryptionFact.Get();    
    auto sendToScreen = senderFact.Get();   
    std::string message;
    std::cout << "Enter your message\n\n";
    std::getline(std::cin, message);
    
    Messenger messenger(message, std::move(noEncryption), std::move(sendToScreen));
    messenger.Send();
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_upper_encryptor_stdin_send_to_screen) 

using namespace messenger; 

    EncryptionFactory fact(1);
    SenderFactory sf;
    auto upper = fact.Get();
    auto sendToScreen = sf.Get();    
    std::string message;
    std::cout << "Enter your message\n\n";
    std::getline(std::cin, message);
    
    Messenger messenger(message, std::move(upper), std::move(sendToScreen));
    messenger.Send();
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_rot13_stdin_send_to_screen)

    using namespace messenger;
    
    EncryptionFactory fact(2);
    SenderFactory sf;
    std::string message;
    std::cout << "Enter your message\n\n";
    std::getline(std::cin, message);
    auto rot13 = fact.Get();
    auto sendToScreen = sf.Get();
    Messenger messenger(message, std::move(rot13), std::move(sendToScreen));
    messenger.Send();

    ASSERT_PASS();
END_TEST


BEGIN_TEST(test_upper_encryptor_read_from_file_send_to_screen) 

using namespace messenger; 

    EncryptionFactory fact(1);
    SenderFactory sf;
    auto upper = fact.Get();
    auto sendToScreen = sf.Get();
    std::ifstream message("test.txt");
    Messenger messenger(message, std::move(upper), std::move(sendToScreen));
    messenger.Send();
    
    ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
    
    // TEST(test_no_encryption_stdin_send_to_screen)     
    // TEST(test_upper_encryptor_stdin_send_to_screen)
    // TEST(test_rot13_stdin_send_to_screen)    
    TEST(test_upper_encryptor_read_from_file_send_to_screen)

END_SUITE




