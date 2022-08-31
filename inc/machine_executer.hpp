#ifndef MACHINE_EXECUTER_H__
#define MACHINE_EXECUTER_H__

#include "machine_stack.hpp"
#include "machine_abstract_executer.hpp"
#include <iostream>
#include <exception>

namespace machineStack{

class Nop : public AbstractExecuter {
public:
    explicit Nop() = default;    
    ~Nop() = default;
    Nop(const Nop& a_other) = default;
    Nop& operator=(const Nop& a_other) = default;

    void operate() {
        return;
    };
};

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

class And : public AbstractExecuter {
public:
    And(MachineStack& a_stack)
    : m_stack(a_stack)
    {}

    ~And() = default;
    And(const And& a_other) = default;
    And& operator=(const And& a_other) = default;
    void operate() {
        int64_t a = m_stack.Remove();
        int64_t b = m_stack.Remove(); 
        m_stack.Add(a & b);
    }

private:
    MachineStack& m_stack;
};

class Or : public AbstractExecuter {
public:
    Or(MachineStack& a_stack)
    : m_stack(a_stack)
    {}
    
    ~Or() = default;
    Or(const Or& a_other) = default;
    Or& operator=(const Or& a_other) = default;
    void operate() {
        int64_t a = m_stack.Remove();
        int64_t b = m_stack.Remove(); 
        m_stack.Add(a | b);
    }

private:
    MachineStack& m_stack;
};

class Xor : public AbstractExecuter {
public:
    Xor(MachineStack& a_stack)
    : m_stack(a_stack)
    {}
    
    ~Xor() = default;
    Xor(const Xor& a_other) = default;
    Xor& operator=(const Xor& a_other) = default;
    void operate() {
        int64_t a = m_stack.Remove();
        int64_t b = m_stack.Remove(); 
        m_stack.Add(a ^ b);
    }

private:
    MachineStack& m_stack;
};

class Not : public AbstractExecuter {
public:
    Not(MachineStack& a_stack)
    : m_stack(a_stack)
    {}
    
    ~Not() = default;
    Not(const Not& a_other) = default;
    Not& operator=(const Not& a_other) = default;
    void operate() {
        int64_t a = m_stack.Remove();         
        m_stack.Add(!a);
    }

private:
    MachineStack& m_stack;
};

class In : public AbstractExecuter {
public:
    In(MachineStack& a_stack)
    : m_stack(a_stack)
    {}
    
    ~In() = default;
    In(const In& a_other) = default;
    In& operator=(const In& a_other) = default;
    void operate() {
        int64_t a;
        std::cin >> a;         
        m_stack.Add(a);
    }

private:
    MachineStack& m_stack;
};

}// machineStack



#endif//MACHINE_EXECUTER_H__