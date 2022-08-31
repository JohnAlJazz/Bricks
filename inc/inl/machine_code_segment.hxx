
#include "machine_code_segment.hpp"

using namespace machineStack;

inline void CodeSegment::MoveIndex(int64_t a_num) {
    m_index += a_num;
}

inline int64_t CodeSegment::Read() {
    int64_t opCode = m_codeSegment[m_index];
    ++m_index;
    return opCode;
}


inline bool CodeSegment::IsProgramEnded() {
    return m_index == static_cast<int64_t>(m_codeSegment.size());
}

