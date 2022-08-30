#include "machine_memory.hpp"


namespace machineStack{

MachineMemory::MachineMemory(unsigned int a_capacity) 
: m_memory(std::vector<int64_t>(a_capacity, 0))
{}                             

} //machineStack