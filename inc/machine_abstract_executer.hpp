#ifndef MACHINE_ABSTRACT_EXECUTER_H__
#define MACHINE_ABSTRACT_EXECUTER_H__

#include <exception>
#include <string>


namespace machineStack{

class AbstractExecuter{
public:
    virtual void operate() = 0;
    virtual ~AbstractExecuter() = default;
    
protected:
    AbstractExecuter(const AbstractExecuter& a_other) = default;
    AbstractExecuter& operator=(const AbstractExecuter& a_other) = default;
    AbstractExecuter() = default;
};






}//machineStack

#endif //MACHINE_ABSTRACT_EXECUTER_H__