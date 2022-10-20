#ifndef SENDER_FACTORY_HPP
#define SENDER_FACTORY_HPP

#include <memory>

#include "ISender.hpp"

namespace messenger {

class SenderFactory {
public:
    explicit SenderFactory(int a_destination = 0);
    std::unique_ptr<ISender> Get() const;

private:
    int m_destination;
};

#include "inl/senderFactory.hxx"
    
} //messenger

#endif //SENDER_FACTORY_HPP