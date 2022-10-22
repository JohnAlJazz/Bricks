#include "IEncryptor.hpp"

#include <unordered_map>
#include <ctype.h>
#include <sstream>
#include <string>

namespace messenger {

RotKEncryptor::RotKEncryptor(int a_rotation)
: m_rotation(a_rotation)
{}

std::string RotKEncryptor::Encrypt(std::string& a_msg) {

    int numOfLetters = 26;

    for(auto& c : a_msg) {
        if(isupper(c)) {
            c = ((c - 'A' + m_rotation) % numOfLetters) + 'A';
        }
        else if(islower(c)) {
            c = ((c - 'a' + m_rotation) % numOfLetters) + 'a';
        }         
    }    
    return a_msg;
}

std::string XorEncryptor::Encrypt(std::string& a_msg) {
        
    std::stringstream ss;

    for(auto& c : a_msg) {
        int n = c;
        n ^= 'B';
        ss << std::hex << n;                 
    }    
    return ss.str();
}

MultiEncryptions::MultiEncryptions(std::vector<std::unique_ptr<IEncryptor>> a_vec) 
: m_vec(std::move(a_vec))
{}

std::string MultiEncryptions::Encrypt(std::string& a_msg) {
    for(auto& enc : m_vec) {
        a_msg = enc->Encrypt(a_msg);
    }
    return a_msg;
}



} //messenger