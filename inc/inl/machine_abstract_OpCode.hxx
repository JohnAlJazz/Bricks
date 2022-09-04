#include "machine_abstract_OpCode.hpp"

namespace machineStack {

inline BinOp::BinOp(MachineStack& a_stack, CodeSegment& a_code)
: m_stack(a_stack)
, m_code(a_code)
{}


int64_t Add::act(int64_t a_first, int64_t a_second) {
    return a_first + a_second;
}

int64_t Sub::act(int64_t a_first, int64_t a_second) {
    return a_first - a_second;
}

int64_t And::act(int64_t a_first, int64_t a_second) {
    return a_first & a_second;
}

int64_t Or::act(int64_t a_first, int64_t a_second) {
    return a_first | a_second;
}

int64_t Xor::act(int64_t a_first, int64_t a_second) {
    return a_first ^ a_second;
}


} //machineStack