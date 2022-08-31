
#include "machine_memory.hpp"

inline void MachineMemory::CheckIndex(int64_t a_idx) {
    if(a_idx >= static_cast<int64_t>(m_memory.capacity())) {
        throw "out of range";
    }
} 

inline int64_t MachineMemory::Read(int64_t a_index) {
    CheckIndex(a_index);
    return m_memory[a_index];
}

inline void MachineMemory::Write(int64_t a_value, int64_t a_index) {
    CheckIndex(a_index);      
    m_memory[a_index] = a_value; 
}