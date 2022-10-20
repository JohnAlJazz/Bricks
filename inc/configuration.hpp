#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

namespace messenger {

//this class will read from a config file => src, dest and encrypt type for the use of the Messenger
class Configuration {
public:

    //TODO => not hard coded 
    int GetSource() const; 
    int GetEncryptionType() const;
    int GetDestination() const;

};

#include "inl/configuration.hxx"

} //messenger

#endif //CONFIGURATION_HPP