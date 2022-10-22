#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <fstream>
#include <string>

namespace messenger {

//this class will read from a config file => src, dest and encrypt type for the use of the Messenger
class Configuration {
public:
    explicit Configuration(std::fstream& a_configFile);    
    std::string GetSource(); 
    std::string GetEncryptionType();
    std::string GetDestination();

private:
    std::string Source();
    std::string Encrypt();
    std::string Destination();

private:
    std::fstream& m_configFile;
    std::string m_source;
    std::string m_destination;
    std::string m_encrypt;
};

#include "inl/configuration.hxx"

} //messenger

#endif //CONFIGURATION_HPP