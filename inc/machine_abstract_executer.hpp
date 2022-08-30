#ifndef MACHINE_ABSTRACT_EXECUTER_H__
#define MACHINE_ABSTRACT_EXECUTER_H__


namespace machineStack{

class AbstractExecuter{
public:
    virtual void operate() = 0;
    ~AbstractExecuter() = default;
    
protected:
    AbstractExecuter(const AbstractExecuter& a_other) = default;
    AbstractExecuter& operator=(const AbstractExecuter& a_other) = default;
    AbstractExecuter() = default;
};


}//machineStack

#endif //MACHINE_ABSTRACT_EXECUTER_H__