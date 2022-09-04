#include <exception>
#include "machine_exceptions.hpp"
#include "machine_stack.hpp"

namespace machineStack {


inline int64_t MachineStack::Remove() {
    if(m_machineStack.empty()) {
        throw StackError("in Remove()", "stack is empty");
    }
    int64_t top = m_machineStack.top();
    m_machineStack.pop();
    return top;
}

inline void MachineStack::Add(int64_t a_element) {
    m_machineStack.push(a_element);
}

inline int64_t MachineStack::Top() {
    return m_machineStack.top();
}


inline int64_t MachineStackIP::Remove() {
    if(m_machineStackIp.empty()) {
        throw StackError("in Remove()", "stack is empty");
    }
    int64_t top = m_machineStackIp.top();
    m_machineStackIp.pop();
    return top;
}

inline void MachineStackIP::Add(int64_t a_element) {
    m_machineStackIp.push(a_element);
}

inline int64_t MachineStackIP::Top() {
    return m_machineStackIp.top();
}

inline int MachineStack::Size() const noexcept {
    return m_machineStack.size();
}

}//