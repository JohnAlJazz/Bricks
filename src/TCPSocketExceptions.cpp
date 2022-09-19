#include "TCPSocketExceptions.hpp"

namespace net {

TCPSocketExceptions::TCPSocketExceptions(const char* a_what, const char* a_where) 
: m_what(a_what)
, m_where(a_where)
{}


} //net