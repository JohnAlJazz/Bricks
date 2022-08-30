#include <map>

#include "machine_executer.hpp"
#include "machine_abstract_executer.hpp"
#include "machine_vm.hpp"
#include "machine_stack.hpp"
#include "machine_code_segment.hpp"
#include "machine_memory.hpp"

namespace machineStack {

 typedef std::map<int64_t, AbstractExecuter*> Map;



MachineVm::MachineVm(std::vector<int64_t> a_forCodeSegment, unsigned int a_capacity)
: m_codeSegment(a_forCodeSegment)
, m_executer()
, m_stack()
, m_memory(a_capacity)
{}


void MachineVm::Run() {  
    m_executer = InitMap();
    int i = 0;
    while(i == 0 && ! m_codeSegment.IsProgramEnded()) {
        int64_t opCode = m_codeSegment.Read();
        Map::const_iterator pos = m_executer.find(opCode);
        AbstractExecuter* value = pos->second;

        value->operate();
    }
}

Map MachineVm::InitMap() {
    Map result;

    result.insert({0, new Add{m_stack}});
    result.insert({1, new Sub{m_stack}});    

    return result;
}


}//machineStack