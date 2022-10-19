#ifndef MESSENGER_HXX
#define MESSENGER_HXX

// Messenger::Messenger(std::string& a_message, std::unique_ptr<IEncryptor> a_encryptor, std::unique_ptr<ISender> a_sender)
// : m_message(a_message)
// , m_encryptor(std::move(a_encryptor))
// , m_sender(std::move(a_sender))
// {}

// inline void Messenger::Send() {
//     auto encrypted = m_encryptor->Encrypt(m_message);
//     m_sender->Send(encrypted);
// }

#endif //MESSENGER_HXX