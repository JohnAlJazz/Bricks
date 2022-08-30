#ifndef CODE_BF_H__
#define CODE_BF_H__

#include "abstract_bf.hpp"
#include <string>

namespace bf {

class CodeBf : public AbstractBf {
public:
    CodeBf(const char* a_code);
    CodeBf(const CodeBf& a_code) = default;
    CodeBf& operator=(const CodeBf& a_code) = default;
    ~CodeBf() = default;

    void operator++() override;
    void operator--() override;
    
    const char& at() const noexcept;
    size_t Size() const noexcept;


private:
    std::string m_code;
    std::string::const_iterator m_itr;
};

} //bf



#endif // CODE_BF_H__