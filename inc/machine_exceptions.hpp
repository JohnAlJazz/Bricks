#ifndef MACHINE_EXCEPTION_H__
#define MACHINE_EXCEPTION_H__

#include <iostream>
#include <string>
#include <exception>


// #include "machine_abstract_executer.hpp"
namespace machineStack {

class AbstractSMError : public std::exception {
public: 
    AbstractSMError(const char* a_func, const char* a_what);
    
    virtual ~AbstractSMError() = default;
    virtual void print() const; 
    virtual const char* what() const throw();

private:
    std::string m_func;
    std::string m_what;  
};


class StackError : public AbstractSMError {
public:
    StackError(const char* a_fn, const char* a_what);
};
}
#include "inl/machine_exceptions.hxx"



#endif //MACHINE_EXCEPTION_H__