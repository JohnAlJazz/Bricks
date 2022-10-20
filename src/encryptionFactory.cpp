#include "encryptionFactory.hpp"

namespace messenger {

std::unique_ptr<IEncryptor> EncryptionFactory::Get() {
    switch(m_encryption) {
        case 0:
            return std::make_unique<NoEncryption>();
        case 1:
            return std::make_unique<UpperCaseEncryptor>();

        case 2:
            return std::make_unique<RotKEncryptor>(13); //TODO - not hard coded

        case 3:
            return std::make_unique<XorEncryptor>();

        default:
            throw 111;            
    }    
}

}//messenger