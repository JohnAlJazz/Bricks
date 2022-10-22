#include "messenger.hpp"

namespace messenger {

Messenger::Messenger(std::unique_ptr<IStream> a_stream, std::unique_ptr<ISender> a_destination, std::unique_ptr<IEncryptor> a_encryptor)
: m_stream(std::move(a_stream))
, m_encryptor(std::move(a_encryptor))
, m_destination(std::move(a_destination))
{}

void Messenger::Send() const {
    while(!m_stream->IsEnd()) {
        auto source = m_stream->Read();
        auto encrypted = m_encryptor->Encrypt(source);
        m_destination->Send(encrypted);
    }
}

} //messenger