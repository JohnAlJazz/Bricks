#ifndef IENCRYPTOR_HXX
#define IENCRYPTOR_HXX

#include <string>

inline std::string UpperCaseEncryptor::Encrypt(std::string& a_msg) {    
    return boost::to_upper_copy<std::string>(a_msg);    
}

inline std::string NoEncryption::Encrypt(std::string& a_msg) {
    return a_msg;
}

#endif //IENCRYPTOR_HXX