#ifndef THREADSPOOL_HXX
#define THREADSPOOL_HXX

namespace threads {

template<typename FunctionObject>
void ThreadsPool::AddTask(FunctionObject& a_task) {    
    // m_tasksQueue.Enqueue(std::unique_ptr<TasksBase> <FunctionObject>{new FunctionObject{a_task}});    
}

} //threads

#endif //THREADS_POOL_HXX