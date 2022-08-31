#ifndef MACHINE_EXCEPTIONS_H__
#define MACHINE_EXCEPTIONS_H__

#include "machine_exceptions.hpp"

namespace machineStack {


inline AbstractSMError::AbstractSMError(const char* a_func, const char* a_what)
: m_func(a_func)
, m_what(a_what)
{}

inline void AbstractSMError::print() const{
    std::cout << m_func << " : " << m_what << '\n';
}

inline const char* AbstractSMError::what() const throw() {     
    return m_what.c_str();    
}

inline StackError::StackError(const char* a_fn, const char* a_what)
: AbstractSMError(a_fn, a_what)
{}


}


#endif //MACHINE_EXCEPTIONS_H__
