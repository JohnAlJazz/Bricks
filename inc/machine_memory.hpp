#ifndef MACHINE_MEMORY_H__
#define MACHINE_MEMORY_H__

#include <vector>
#include <cstdint>

namespace machineStack {

class MachineMemory {
public:
    MachineMemory() = delete;
    explicit MachineMemory(unsigned int a_capacity);
    MachineMemory(const MachineMemory& a_other) = default;
    MachineMemory& operator=(const MachineMemory& a_other) = default;
    ~MachineMemory() = default;   

    int64_t Read(int64_t a_index);
    void Write(int64_t a_value, int64_t a_index);      


private:
    std::vector<int64_t> m_memory;

private:
    void CheckIndex(int64_t a_idx);
};

#include "inl/machine_memory.hxx"

} //machineStack


#endif // MACHINE_MEMORY_H__