#ifndef ISTREAM_HPP
#define ISTREAM_HPP

#include <string>
#include <fstream>

namespace messenger {

class IStream {
public:
    virtual ~IStream() = default;
    virtual std::string Read() = 0;

protected: 
    IStream() = default;
    IStream(const IStream&) = default;
    IStream& operator=(const IStream&) = default;
};

class Stdin : public IStream {
public:
    std::string Read() override;
};

class File : public IStream {
public:
    File(std::ifstream& a_file);
    std::string Read() override;

private:
    std::ifstream& m_file;
};

} //messenger 

#endif //ISTREAM_HPP
