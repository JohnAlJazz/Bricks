
#include "machine_code_segment.hpp"

using namespace machineStack;

inline void CodeSegment::MoveIndex(int64_t a_num) {
    m_index += a_num;
}

inline int64_t CodeSegment::Read() {
    return m_codeSegment[m_index];
}

inline bool CodeSegment::IsProgramEnded() {
    return m_index == static_cast<int64_t>(m_codeSegment.size());
}

inline void CodeSegment::SetIndex(int64_t a_num){
    m_index = a_num;
}