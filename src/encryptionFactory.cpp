#include "encryptionFactory.hpp"

namespace messenger {

std::unique_ptr<IEncryptor> EncryptionFactory::Get() {
    switch(m_encryption) {
        case 0:
            return std::make_unique<NoEncryption>();
        case 1:
            return std::make_unique<UpperCaseEncryptor>();

        case 2:
            return std::make_unique<Rot13Encryptor>();

        case 3:
            return std::make_unique<XorEncryptor>();

        default:
            throw 111;
            // std::runtime_error("no such encryption is available\n");
            // return nullptr;
    }    
}

}//messenger