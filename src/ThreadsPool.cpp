#include "ThreadsPool.hpp"
#include "TaskBase.hpp"

#include <exception>

namespace threads {

ThreadsPool::ThreadsPool(size_t a_numOfThreads)
: m_tasksQueue()
, m_isDone(false)
, m_numOfThreads(a_numOfThreads)
{
    PushThreads(a_numOfThreads);
}

ThreadsPool::~ThreadsPool() {
    for(size_t i = 0; i < m_numOfThreads; ++i) {
        m_threads[i].join();
    }
}

void ThreadsPool::AddTask(std::unique_ptr<TasksBase> a_task) {    
    if(!m_isDone) {
        m_tasksQueue.Enqueue(std::move(a_task));              
    }
    else {
        std::cerr << "Can't add tasks\n";
    }    
} 

void ThreadsPool::AddTask(std::shared_ptr<TasksBase> a_task) {
    if(!m_isDone) {        
        m_tasksQueue.Enqueue(a_task);              
    }
    else {
        std::cerr << "Can't add tasks\n";
    }
}

void ThreadsPool::AddTask(std::function<void()> a_func) {
    if(!m_isDone) {
        m_tasksQueue.Enqueue(std::shared_ptr<TasksBase>(new Function{a_func}));
    } 
    else {
        std::cerr << "Can't add tasks\n";
    }   
}

void ThreadsPool::AddThreads(size_t a_numOfThreads) {
    PushThreads(a_numOfThreads);
    m_numOfThreads += a_numOfThreads;
}


struct TaskExceptions : public std::runtime_error {
    TaskExceptions() : std::runtime_error("") {}
};

class ShutDownTask : public TasksBase {
    void Act() override {
        throw TaskExceptions();
    }
};

void ThreadsPool::SendToInternalAddTask(size_t a_numOfThreads) {
    for(size_t i = 0; i < a_numOfThreads; ++i) {
       InternalAddTask(std::make_unique<ShutDownTask>());
    }
}

void ThreadsPool::RemoveThreads(size_t a_numOfThreads) {
    if(a_numOfThreads > m_numOfThreads) {
        a_numOfThreads = m_numOfThreads;
    }
    SendToInternalAddTask(a_numOfThreads);    
}

void ThreadsPool::ShutDown() {
    m_isDone = true;
    size_t numOfThreads = m_threads.size();
    SendToInternalAddTask(numOfThreads);
}

void ThreadsPool::ShutDownImmediately() {
    size_t numOfThreads = m_threads.size();
    for(size_t i = 0; i < numOfThreads; ++i) {
        m_tasksQueue.ProtectionEnqueue(std::make_shared<ShutDownTask>());        
    }
}

void ThreadsPool::PushThreads(size_t a_numOfThreads) {
    for(size_t i = 0; i < a_numOfThreads; ++i) {
        m_threads.push_back(std::thread{&ThreadsPool::Run, this});
    } 
}

void ThreadsPool::InternalAddTask(std::unique_ptr<TasksBase> a_task) {    
    m_tasksQueue.Enqueue(std::move(a_task));    
}

void ThreadsPool::Run() {
    while(true) {    
        try {             
            std::shared_ptr<TasksBase> task;
            m_tasksQueue.Dequeue(task); 
            task->Act();

        } catch(const TaskExceptions&) {            
            break;

        } catch(...) { //user's task exceptions
            continue;
        }        
    }       
}

} //threads