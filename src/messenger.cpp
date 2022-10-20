#include "messenger.hpp"

namespace messenger {

Messenger::Messenger(std::unique_ptr<IStream> a_stream, std::unique_ptr<IEncryptor> a_encryptor, std::unique_ptr<ISender> a_destination)
: m_stream(std::move(a_stream))
, m_encryptor(std::move(a_encryptor))
, m_destination(std::move(a_destination))
{}

void Messenger::Send() const {
    auto source = m_stream->Read();
    auto encrypted = m_encryptor->Encrypt(source);
    m_destination->Send(encrypted);
}

} //messenger