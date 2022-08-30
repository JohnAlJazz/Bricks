#ifndef MACHINE_STACK_H__
#define MACHINE_STACK_H__

#include <stack>
#include <cstdint> /*int64_t*/

namespace machineStack {

class MachineStack {
public:
    MachineStack();
    MachineStack(const MachineStack& a_other) = default;
    MachineStack& operator=(const MachineStack& a_other) = default;
    ~MachineStack() = default;

    void Add(int64_t a_element);
    int64_t Remove();

private:
    std::stack<int64_t> m_machineStack;
};

#include "inl/machine_stack.hxx"

} //machineStack


#endif //