#include "senderFactory.hpp"

namespace messenger {

std::unique_ptr<ISender> SenderFactory::Get() const{
     switch(m_destination) {
        case 0:
            return std::make_unique<SendToScreen>();
        case 1:
            return std::make_unique<SendToFile>();
       
        default:
            throw 111;            
    }    
}

} //messenger