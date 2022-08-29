#include "code_bf.hpp"

typedef bf::CodeBf CodeBf;

CodeBf::CodeBf(const char* a_code)
: m_code(a_code)
, m_itr(m_code.cbegin())
{}
