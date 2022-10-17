#ifndef TASK_HPP
#define TASK_HPP

#include <functional>

#include "TaskBase.hpp"

namespace threads {

template <typename Arg>
class Task : public TasksBase {    
    using Func = void(*)(Arg);
    
public:
    Task(Func a_func, Arg a_arg);
    void Act() override;

private:
    Func m_func;
    Arg m_arg;
};

template <typename F>
class FunctionObject : public TasksBase {
public: 
    FunctionObject(F& a_funcObject);
    void Act() override;    

private:
    F& m_funcObject;
};


class Function : public TasksBase {
public:
    Function(std::function<void()>& a_function);
    void Act() override;

private:
    std::function<void()>& m_function;
};

} //threads

#include "inl/Task.hxx"

#endif //TASK_HPP