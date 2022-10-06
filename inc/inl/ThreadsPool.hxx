#ifndef THREADSPOOL_HXX
#define THREADSPOOL_HXX

namespace threads {

inline ThreadsPool::ThreadsPool()
: m_tasksQueue()
{}

template<typename FunctionObjectT>
void ThreadsPool::AddTask(FunctionObjectT a_task) {
    TasksBase* ptr = new Task{a_task};        
    m_tasksQueue.Enqueue(ptr);
}


} //threads

#endif //THREADS_POOL_HXX