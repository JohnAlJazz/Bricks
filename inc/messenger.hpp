#ifndef MESSENGER_HPP
#define MESSENGER_HPP

#include <memory>
#include <string>
#include <fstream>

#include "IEncryptor.hpp"
#include "ISender.hpp"

namespace messenger{

class Messenger {
public:
    Messenger(std::string& a_message, std::unique_ptr<IEncryptor> a_encryptor, std::unique_ptr<ISender> a_sender);
    Messenger(std::ifstream& a_file, std::unique_ptr<IEncryptor> a_encryptor, std::unique_ptr<ISender> a_sender);
    void Send();

private:
    std::string ReadFromFile(std::ifstream& a_file);

private:
    std::string m_message;
    std::unique_ptr<IEncryptor> m_encryptor;
    std::unique_ptr<ISender> m_sender;
};

#include "inl/messenger.hxx"

} //messsenger

#endif //MESSENGER_HPP