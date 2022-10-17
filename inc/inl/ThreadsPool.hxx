#ifndef THREADSPOOL_HXX
#define THREADSPOOL_HXX

namespace threads {

template<typename FuncObj>
void ThreadsPool::AddTask(FuncObj& a_funcObj) {  
    if(!m_isDone) {   
        m_tasksQueue.Enqueue(std::shared_ptr<TasksBase>(new FunctionObject{a_funcObj}));  
    }
    else {
        std::cerr << "Can't add tasks\n";
    }
}

} //threads

#endif //THREADS_POOL_HXX