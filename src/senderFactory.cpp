#include "senderFactory.hpp"

namespace messenger {

std::unique_ptr<ISender> SenderFactory::Get() const{
     switch(m_destination) {
        case 0:
            return std::make_unique<SendToScreen>();
        case 1:
            return std::make_unique<SendToFile>();

        // case 2:
        //     return std::make_unique<Rot13Encryptor>();

        // case 3:
        //     return std::make_unique<XorEncryptor>();

        default:
            throw 111;
            // std::runtime_error("no such encryption is available\n");
            // return nullptr;
    }    
}

} //messenger