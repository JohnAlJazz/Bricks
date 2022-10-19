#ifndef IENCRYPTOR_HPP
#define IENCRYPTOR_HPP

#include <string>
#include <boost/algorithm/string.hpp>

namespace messenger {

class IEncryptor {
public:
    virtual ~IEncryptor() = default;    
    virtual std::string Encrypt(std::string& a_msg) = 0;
};

class Rot13Encryptor : public IEncryptor {
public:    
    std::string Encrypt(std::string& a_msg) override;
};

class XorEncryptor : public IEncryptor {
public:
    std::string Encrypt(std::string& a_msg) override;      
};

class UpperCaseEncryptor : public IEncryptor {
public:
    std::string Encrypt(std::string& a_msg) override;    
};

class NoEncryption : public IEncryptor {
public:
    std::string Encrypt(std::string& a_msg) override;
};

#include "inl/IEncryptor.hxx"

} //messsenger

#endif //IENCRYPTOR_HPP