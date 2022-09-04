#ifndef MACHINE_ABSTRACT_OPCODE_H__
#define MACHINE_ABSTRACT_OPCODE_H__

#include <exception>
#include <string>
#include <stack>

#include "machine_stack.hpp"
#include "machine_code_segment.hpp"


namespace machineStack{

class AbstractOpCode{
public:
    virtual void operator()() = 0;
    virtual ~AbstractOpCode() = default;
    
protected:
    AbstractOpCode(const AbstractOpCode& a_other) = default;
    AbstractOpCode& operator=(const AbstractOpCode& a_other) = default;
    AbstractOpCode() = default;
};


class BinOp : public AbstractOpCode {
public:
    BinOp(MachineStack& a_stack, CodeSegment& a_code);
    void operator()() override;

private:
    virtual int64_t act(int64_t a_first, int64_t a_second) = 0;

private:
    MachineStack& m_stack;
    CodeSegment& m_code;    
};

class Add : public BinOp {
public:
   using BinOp::BinOp;
   int64_t act(int64_t a_first, int64_t a_second) override;
};

class Sub : public BinOp {
public:
   using BinOp::BinOp;
   int64_t act(int64_t a_first, int64_t a_second) override;
};

class And : public BinOp {
public:
   using BinOp::BinOp;
   int64_t act(int64_t a_first, int64_t a_second) override;
};

class Or : public BinOp {
public:
   using BinOp::BinOp;
   int64_t act(int64_t a_first, int64_t a_second) override;
};

class Xor : public BinOp {
public:
   using BinOp::BinOp;
   int64_t act(int64_t a_first, int64_t a_second) override;
};


} //machineStack

#include "inl/machine_abstract_OpCode.hxx"

#endif //MACHINE_ABSTRACT_OPCODE_H__