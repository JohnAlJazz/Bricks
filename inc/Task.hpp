#ifndef TASK_HPP
#define TASK_HPP

#include "TaskBase.hpp"

namespace threads {

template <typename Arg>
class Task : public TasksBase {    
    typedef void(*Func)(Arg);
    
public:
    Task(Func a_func, Arg a_arg);
    Task(const Task&) = default;
    Task& operator=(const Task&) = default;
    ~Task() = default;

    void Act() override;

private:
    Func m_func;
    Arg m_arg;
};


} //threads

#include "inl/Task.hxx"

#endif //TASK_HPP