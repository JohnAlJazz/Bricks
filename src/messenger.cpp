#include "messenger.hpp"

namespace messenger {

Messenger::Messenger(std::string& a_message, std::unique_ptr<IEncryptor> a_encryptor, std::unique_ptr<ISender> a_sender)
: m_message(a_message)
, m_encryptor(std::move(a_encryptor))
, m_sender(std::move(a_sender))
{}

Messenger::Messenger(std::ifstream& a_file, std::unique_ptr<IEncryptor> a_encryptor, std::unique_ptr<ISender> a_sender)
: m_message(ReadFromFile(a_file))
, m_encryptor(std::move(a_encryptor))
, m_sender(std::move(a_sender))
{}

void Messenger::Send() {
    auto encrypted = m_encryptor->Encrypt(m_message);
    m_sender->Send(encrypted);
}

std::string Messenger::ReadFromFile(std::ifstream& a_file) {

    std::string read;
    std::string next;

    while(!a_file.eof()) {
        a_file >> next;
        read += next; 
        read += " ";       
    }
    return read;
}

} //messenger