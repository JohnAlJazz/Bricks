#ifndef VM_BF_H__
#define VM_BF_H__

#include "code_bf.hpp"
#include "data_bf.hpp"

namespace bf {

class VmBf {
public:
    VmBf(const char* a_code);
    VmBf(const VmBf& a_vm) = default;
    VmBf& operator=(const VmBf& a_vm) = default;
    ~VmBf() = default;

    void Run();
    void DecideByChar(VmBf& a_vm, const char& a_m);

private:
    CodeBf m_codeBf;
    DataBf m_dataBf;
};

} //bf
#endif // VM_BF_H__