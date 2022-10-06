#include "ThreadsPool.hpp"
#include "TaskBase.hpp"

namespace threads {

void ThreadsPool::AddTask(std::unique_ptr<TasksBase> a_task) {
    m_tasksQueue.Enqueue(a_task.release());
} 

void ThreadsPool::ThreadsLoop() {

    while(true) {        
        TasksBase* t;
        m_tasksQueue.Dequeue(&t); 
        t->Act();
        delete t;
    }
}

void ThreadsPool::Run(unsigned int a_numOfThreads) {
    for(unsigned int i = 0; i < a_numOfThreads; ++i) {
        m_threads.push_back(std::thread{&ThreadsPool::ThreadsLoop, this});
    }
    for(auto& e : m_threads) {
        e.join();
    }    
}

} //threads