#ifndef MACHINE_EXECUTER_H__
#define MACHINE_EXECUTER_H__

#include "machine_stack.hpp"
#include "machine_abstract_executer.hpp"

namespace machineStack{

class Add : public AbstractExecuter {
public:
    explicit Add(MachineStack& a_stack) 
    : stack(a_stack)
    {}
    ~Add() = default;
    Add(const Add& a_other) = default;
    Add& operator=(const Add& a_other) = default;

    void operate() {

        int64_t a = stack.Remove();
        int64_t b = stack.Remove();
        stack.Add(a + b);
    };
private:
    MachineStack& stack;
};

class Sub : public AbstractExecuter {
public:
    explicit Sub(MachineStack& a_stack)
    : stack(a_stack)
    {} 
    ~Sub() = default;
    Sub(const Sub& a_other) = default;
    Sub& operator=(const Sub& a_other) = default;

    void operate() {
        int64_t a = stack.Remove();
        int64_t b = stack.Remove();
        stack.Add(a - b);
    };
private:
    MachineStack& stack;
};


}// machineStack



#endif//MACHINE_EXECUTER_H__