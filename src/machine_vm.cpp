#include <map>

#include "machine_executer.hpp"
#include "machine_abstract_executer.hpp"
#include "machine_vm.hpp"
#include "machine_stack.hpp"
#include "machine_code_segment.hpp"
#include "machine_memory.hpp"
#include "machine_exceptions.hpp"

namespace machineStack {

 typedef std::map<int64_t, AbstractExecuter*> Map;



MachineVm::MachineVm(std::vector<int64_t> a_forCodeSegment, std::stack<int64_t> a_stack,  unsigned int a_capacity)
: m_codeSegment(a_forCodeSegment)
, m_executer()
, m_stack(a_stack)
, m_memory(a_capacity)
{}


void MachineVm::Run() {  
    m_executer = InitMap();
    int i = 0;
    m_stack.Add(2);
    m_stack.Add(3);
    m_stack.Add(4);
    m_stack.Add(1);
    m_stack.Add(2);
    m_stack.Add(0);

    while(i == 0 && ! m_codeSegment.IsProgramEnded()) {
        int64_t opCode = m_codeSegment.Read();
        Map::const_iterator pos = m_executer.find(opCode);
        AbstractExecuter* value = pos->second;

         value->operate();
        // try{
        // }
        // catch (StackError const& e) {
        //     e.print();
        //     return;
        // }
        }
    }

Map MachineVm::InitMap() {
    Map result;

    result.insert({0, new Nop{}});
    result.insert({1, new Add{m_stack}});
    result.insert({2, new Sub{m_stack}});
    result.insert({3, new And{m_stack}}); 
    result.insert({4, new Or{m_stack}}); 
    result.insert({5, new Xor{m_stack}});
    result.insert({6, new Not{m_stack}});
    result.insert({7, new In{m_stack}});    

    return result;
}

int64_t MachineVm::Top() {
    return m_stack.Top();
}

}