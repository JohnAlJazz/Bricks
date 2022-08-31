#include "machine_stack.hpp"
#include <iostream>

namespace machineStack {

MachineStack::MachineStack(std::stack<int64_t> a_stk)
: m_machineStack(a_stk)
{}

MachineStackIP::MachineStackIP(std::stack<int64_t> a_stkIp)
: m_machineStackIp(a_stkIp)
{}

} //machineStack 