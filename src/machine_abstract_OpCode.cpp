#include "machine_abstract_OpCode.hpp"


namespace machineStack {

void BinOp::operator()() {
    if(m_stack.Size() < 2) {
        throw 77;
    }
    else {
        int64_t a = m_stack.Remove();
        int64_t b = m_stack.Remove();
        m_stack.Add(act(a, b));
        m_code.MoveIndex(1);
    }
}




} //machineStack