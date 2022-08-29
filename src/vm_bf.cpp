#include "vm_bf.hpp"
#include <stdio.h>

namespace bf {

VmBf::VmBf(const char* a_code) 
: m_codeBf(a_code)
, m_dataBf()
{}


void VmBf::Run() {
    size_t length = m_codeBf.Size();
    for(size_t i = 0; i < length; ++i) {
        DecideByChar(*this, m_codeBf.at());
    }
}

void VmBf::DecideByChar(VmBf& a_vm, const char& a_c) {
    switch (a_c)
    {
    case '>':
        ++(a_vm.m_dataBf);
        break;
    case '<':
        --(a_vm.m_dataBf);
        break;
    case '+':
        a_vm.m_dataBf.IncrementValue();
        break;
    case '-':
        a_vm.m_dataBf.DecrementValue();
        break;
    case '.':
        a_vm.m_dataBf.PrintValue();
        break;
    default:
        break;
    }
    ++(a_vm.m_codeBf);
}

#include "inl/bf.hxx"

} //bf