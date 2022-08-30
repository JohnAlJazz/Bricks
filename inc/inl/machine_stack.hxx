

inline int64_t MachineStack::Remove() {
    int64_t top = m_machineStack.top();
    m_machineStack.pop();
    return top;
}

inline void MachineStack::Add(int64_t a_element) {
    m_machineStack.push(a_element);
}

