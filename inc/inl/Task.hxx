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

template <typename F>
FunctionObject<F>::FunctionObject(F& a_funcObject) 
: m_funcObject(a_funcObject)
{}

template <typename F>
void FunctionObject<F>::Act() {
    m_funcObject();
}

inline Function::Function(std::function<void()>& a_function) 
: m_function(a_function) 
{}

inline void Function::Act() {
    m_function();
}

} //threads

#endif //TASK_HXX