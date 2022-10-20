#include "messengerFactory.hpp"

namespace messenger {

MessengerFactory::MessengerFactory() 
: m_config()
, m_source(m_config.GetSource())
, m_encryption(m_config.GetEncryptionType())
, m_destination(m_config.GetDestination())
{}

std::unique_ptr<Messenger> MessengerFactory::Get() {
    auto source = m_source.Get();
    auto encryption = m_encryption.Get();
    auto destination = m_destination.Get();
    return std::make_unique<Messenger>(std::move(source), std::move(encryption), std::move(destination));    
}

} //messenger