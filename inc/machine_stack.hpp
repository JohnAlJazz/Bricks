#ifndef MACHINE_STACK_H__
#define MACHINE_STACK_H__

#include <stack>
#include <cstdint> /*int64_t*/
#include "machine_abstract_OpCode.hpp"

namespace machineStack {

class MachineStack {
public:
    MachineStack(std::stack<int64_t> a_stk);
    MachineStack(const MachineStack& a_other) = default;
    MachineStack& operator=(const MachineStack& a_other) = default;
    ~MachineStack() = default;

    void Add(int64_t a_element);
    int64_t Remove();
    int64_t Top();
    int Size() const noexcept;

private:
    std::stack<int64_t> m_machineStack;
};

class MachineStackIP {
public:
    MachineStackIP(std::stack<int64_t> a_stk);
    MachineStackIP(const MachineStackIP& a_other) = default;
    MachineStackIP& operator=(const MachineStackIP& a_other) = default;
    ~MachineStackIP() = default;

    void Add(int64_t a_element);
    int64_t Remove();
    int64_t Top();

private:
    std::stack<int64_t> m_machineStackIp;
};



} //machineStack

#include "inl/machine_stack.hxx"


#endif //