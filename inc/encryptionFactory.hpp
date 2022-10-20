#ifndef ENCRYPTION_FACTORY_HPP
#define ENCRYPTION_FACTORY_HPP

#include <memory>

#include "IEncryptor.hpp"

namespace messenger {

class EncryptionFactory {
public:
    explicit EncryptionFactory(int a_encryption = 0);
    std::unique_ptr<IEncryptor> Get();

private:
    int m_encryption;
};

#include "inl/encryptionFactory.hxx"

} //messenger

#endif //ENCRYPTION_FACTORY_HPP

#include "inl/encryptionFactory.hxx"