#ifndef MACHINE_EXECUTER_H__
#define MACHINE_EXECUTER_H__

#include "machine_stack.hpp"
#include "machine_abstract_OpCode.hpp"
#include "machine_exceptions.hpp"
#include "machine_memory.hpp"
#include "machine_code_segment.hpp"
#include <iostream>
#include <exception>

namespace machineStack{

class Nop : public AbstractOpCode {
public:
    explicit Nop(CodeSegment& a_code)
    : m_code(a_code)
    {}   
    ~Nop() = default;
    Nop(const Nop& a_other) = default;
    Nop& operator=(const Nop& a_other) = default;

    void operate() {
        m_code.MoveIndex(1);
        return;
    };
private:
    CodeSegment& m_code;   
};


 
class Not : public AbstractOpCode {
public:
    Not(MachineStack& a_stack, CodeSegment& a_code)
    : m_stack(a_stack)
    , m_code(a_code)
    {}
    
    ~Not() = default;
    Not(const Not& a_other) = default;
    Not& operator=(const Not& a_other) = default;
    void operate() {
        int64_t a = m_stack.Remove();         
        m_stack.Add(!a);
        m_code.MoveIndex(1);
    }

private:
    MachineStack& m_stack;
    CodeSegment& m_code;
};

class In : public AbstractOpCode {
public:
    In(MachineStack& a_stack, CodeSegment& a_code)
    : m_stack(a_stack)
    , m_code(a_code)
    {}
    
    ~In() = default;
    In(const In& a_other) = default;
    In& operator=(const In& a_other) = default;
    void operate() {
        int64_t a;
        std::cin >> a;         
        m_stack.Add(a);
        m_code.MoveIndex(1);
    }

private:
    MachineStack& m_stack;
    CodeSegment& m_code;  
};

class Out : public AbstractOpCode {
public:
    Out(MachineStack& a_stack, CodeSegment& a_code)
    : m_stack(a_stack)
    , m_code(a_code)
    {}
    
    ~Out() = default;
    Out(const Out& a_other) = default;
    Out& operator=(const Out& a_other) = default;
    void operate() {
        int64_t a = m_stack.Remove();
        if(a < 33 || a > 126){
            throw StackError("in Out()", "no char within this range");
        } 
        printf("%c\n", static_cast<char>(a));  
        m_code.MoveIndex(1);         
    }
private:
    MachineStack& m_stack;
    CodeSegment& m_code;
};


class Load : public AbstractOpCode {
public:
    Load(MachineStack& a_stack, CodeSegment& a_code, MachineMemory& a_memory)
    : m_stack(a_stack)
    , m_code(a_code)
    , m_memory(a_memory)
    {}
    
    ~Load() = default;
    Load(const Load& a_other) = default;
    Load& operator=(const Load& a_other) = default;
    void operate() {
       int64_t a = m_stack.Remove();
       int64_t read = m_memory.Read(a);
       m_stack.Add(read);  
       m_code.MoveIndex(1);                
    }
private:
    MachineStack& m_stack;
    CodeSegment& m_code;
    MachineMemory& m_memory;
};


class Stor : public AbstractOpCode {
public:
    Stor(MachineStack& a_stack, CodeSegment& a_code, MachineMemory& a_memory)
    : m_stack(a_stack)
    , m_code(a_code)
    , m_memory(a_memory)
    {}
    
    ~Stor() = default;
    Stor(const Stor& a_other) = default;
    Stor& operator=(const Stor& a_other) = default;
    void operate() {
       int64_t a = m_stack.Remove();
       int64_t b = m_stack.Remove();
       m_memory.Write(b, a);         
       m_code.MoveIndex(1);                
    }
private:
    MachineStack& m_stack;
    CodeSegment& m_code;
    MachineMemory& m_memory;
};


class Jmp : public AbstractOpCode {
public:
    Jmp(MachineStack& a_stack, CodeSegment& a_code)
    : m_stack(a_stack)
    , m_code(a_code)    
    {}
    
    ~Jmp() = default;
    Jmp(const Jmp& a_other) = default;
    Jmp& operator=(const Jmp& a_other) = default;
    void operate() {
       int64_t a = m_stack.Remove();       
       m_code.SetIndex(a);                          
    }
private:
    MachineStack& m_stack;
    CodeSegment& m_code;    
};


class PUSHIP : public AbstractOpCode {
public:
    PUSHIP(MachineStackIP& a_stackIp, CodeSegment& a_code)
    : m_stackIp(a_stackIp)
    , m_code(a_code)       
    {}
    
    ~PUSHIP() = default;
    PUSHIP(const PUSHIP& a_other) = default;
    PUSHIP& operator=(const PUSHIP& a_other) = default;
    void operate() {
       m_code.MoveIndex(1);
       int64_t a = m_code.Read();
       m_stackIp.Add(a); 
       m_code.MoveIndex(1);                            
    }
private:
    MachineStackIP& m_stackIp;
    CodeSegment& m_code;  
};

class DROPIP : public AbstractOpCode {
public:
    DROPIP(MachineStackIP& a_stackIp, CodeSegment& a_code)
    : m_stackIp(a_stackIp)
    , m_code(a_code)       
    {}
    
    ~DROPIP() = default;
    DROPIP(const DROPIP& a_other) = default;
    DROPIP& operator=(const DROPIP& a_other) = default;
    void operate() {
       m_stackIp.Remove();
       m_code.MoveIndex(1);                         
    }
private:
    MachineStackIP& m_stackIp;
    CodeSegment& m_code;  
};

}// machineStack



#endif//MACHINE_EXECUTER_H__