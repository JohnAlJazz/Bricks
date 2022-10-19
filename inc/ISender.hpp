#ifndef ISENDER_HPP
#define ISENDER_HPP

#include <iostream>
#include <string>

namespace messenger {

class ISender {
public:
    virtual ~ISender() = default;
    virtual void Send(std::string& a_message) = 0;
};

class SendToScreen : public ISender {
public:    
    void Send(std::string& a_message) override;
};

class SendToFile : public ISender {
    void Send(std::string& a_message) override;
};

// class SendToTcpSocket : public ISender {

// private:
//     const std::string& m_message;
// };

#include "inl/Isender.hxx"

} //messsenger

#endif //ISENDER_HPP