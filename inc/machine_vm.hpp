#ifndef MACHINE_VM_H__
#define MACHINE_VM_H__

#include <map>
#include "machine_code_segment.hpp"
#include "machine_abstract_executer.hpp"
#include "machine_memory.hpp"
#include "machine_stack.hpp"

namespace machineStack{


class MachineVm {
public:
    typedef std::stack<int64_t> Stack;
    MachineVm() = delete;
    MachineVm(std::vector<int64_t> a_forCodeSegment, Stack a_stack, unsigned int a_capacity, Stack a_stackIp);
    ~MachineVm() = default;
    MachineVm(const MachineVm& a_other) = default;
    MachineVm& operator=(MachineVm& a_other) = default;

    void Run();
    int64_t Top();
    int64_t GetMemory(int64_t a_idx);

private:
    CodeSegment m_codeSegment;
    typedef std::map<int64_t, AbstractExecuter*> Map;
    Map m_executer;
    MachineStack m_stack;
    MachineMemory m_memory;
    MachineStack m_stackIp;

private:
    Map InitMap();
};


} //machineStack


#endif //MACHINE_VM_H__