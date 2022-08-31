#include <exception>
#include "machine_exceptions.hpp"
#include "machine_stack.hpp"

namespace machineStack {

inline int64_t MachineStack::Remove() {
    if(m_machineStack.empty()) {
        throw StackError("Remove", "stack is empty");
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

}//