#include "IEncryptor.hpp"

#include <unordered_map>

namespace messenger {

std::string Rot13Encryptor::Encrypt(std::string& a_msg) {

    for(auto& c : a_msg) {
        if((c >= 'a' && c < 'n') || (c >= 'A' && c < 'N')) {
            c += 13;
        }
        else if((c >= 'n' && c < 'z') || (c >= 'N' && c < 'Z')) {
            c -= 13;
        }         
    }    
    return a_msg;
}

} //messenger