#ifndef TASK_HXX
#define TASK_HXX

namespace threads {

template <typename Arg>
Task<Arg>::Task(Func a_func, Arg a_arg) 
: m_func(a_func)
, m_arg(a_arg)
{}

template <typename Arg>
void Task<Arg>::Act() {
    m_func(m_arg);
}


} //threads

#endif //TASK_HXX