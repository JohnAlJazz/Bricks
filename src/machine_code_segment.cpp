#include "machine_code_segment.hpp"

namespace machineStack{


CodeSegment::CodeSegment(std::vector<int64_t> a_code)
: m_codeSegment(a_code)
, m_index(0)
{}


} //machineStack