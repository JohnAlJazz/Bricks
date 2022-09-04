#include <map>

#include "machine_executer.hpp"
#include "machine_abstract_OpCode.hpp"
#include "machine_vm.hpp"
#include "machine_stack.hpp"
#include "machine_code_segment.hpp"
#include "machine_memory.hpp"
#include "machine_exceptions.hpp"

namespace machineStack {

 typedef std::map<int64_t, AbstractOpCode*> Map;
 typedef std::stack<int64_t> Stack;


MachineVm::MachineVm(std::vector<int64_t> a_forCodeSegment, Stack a_stack, unsigned int a_capacity, Stack a_stackIp)
: m_codeSegment(a_forCodeSegment)
, m_executer()
, m_stack(a_stack)
, m_memory(a_capacity)
, m_stackIp(a_stackIp)
{}


void MachineVm::Run() {  
    m_executer = InitMap();
    int i = 0;
    m_stack.Add(2);
    m_stack.Add(3);
    m_stack.Add(4);
    m_stack.Add(1);
    m_stack.Add(2);
    m_stack.Add(4);

    while(i == 0 && ! m_codeSegment.IsProgramEnded()) {
        int64_t opCode = m_codeSegment.Read();
        Map::const_iterator pos = m_executer.find(opCode);
        AbstractOpCode* value = pos->second;

            try{
                value->operator()();
            }
            catch (StackError const& e) {
                e.print();
                break;
            }
        }
    }

Map MachineVm::InitMap() {
    Map result;

    result.insert({0, new Nop{m_codeSegment}});
    result.insert({1, new Add{m_stack, m_codeSegment}});
    result.insert({2, new Sub{m_stack, m_codeSegment}});
    result.insert({3, new And{m_stack, m_codeSegment}}); 
    result.insert({4, new Or{m_stack, m_codeSegment}}); 
    result.insert({5, new Xor{m_stack, m_codeSegment}});
    result.insert({6, new Not{m_stack, m_codeSegment}});
    result.insert({7, new In{m_stack, m_codeSegment}});
    result.insert({8, new Out{m_stack, m_codeSegment}});
    result.insert({9, new Load{m_stack, m_codeSegment, m_memory}}); 
    result.insert({10, new Stor{m_stack, m_codeSegment, m_memory}});
    result.insert({11, new Jmp{m_stack, m_codeSegment}});
    result.insert({12, new PUSHIP{m_stackIp, m_codeSegment}});
    result.insert({13, new POPIP{m_stackIp, m_codeSegment}});
    result.insert({14, new DROPIP{m_stackIp, m_codeSegment}});    

    return result;
}

int64_t MachineVm::Top() {
    return m_stack.Top();
}

int64_t MachineVm::GetMemory(int64_t a_idx) {
    return m_memory.Read(a_idx);
}

} 