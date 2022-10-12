#include "ThreadsPool.hpp"
#include "TaskBase.hpp"

#include <exception>

namespace threads {

ThreadsPool::ThreadsPool(size_t a_numOfThreads)
: m_tasksQueue()
, m_isDone(false)
{
    for(size_t i = 0; i < a_numOfThreads; ++i) {
        m_threads.push_back(std::thread{&ThreadsPool::Run, this});
    }    
}

ThreadsPool::~ThreadsPool() {
    for(auto& e : m_threads) {
        e.join();
    }
}

void ThreadsPool::AddTask(std::unique_ptr<TasksBase> a_task) {
    if(!m_isDone) {
        InternalAddTask(std::move(a_task));              
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

void ThreadsPool::AddThreads(size_t numOfThreads) {
    for(size_t i = 0; i < numOfThreads; ++i) {
        m_threads.push_back(std::thread{&ThreadsPool::Run, this});
    }
}

void ThreadsPool::RemoveThreads(size_t numOfThreads) {
    for(size_t i = 0; i < numOfThreads; ++i) {
        m_threads.pop_back();
    }
}

struct TaskExceptions : public std::runtime_error {
    TaskExceptions() : std::runtime_error("") {}
};

class ShutDownTask : public TasksBase {
    void Act() override {
        throw TaskExceptions();
    }
};

void ThreadsPool::ShutDown() {
    m_isDone = true;
    size_t numOfThreads = m_threads.size();
    for(size_t i = 0; i < numOfThreads; ++i) {
        InternalAddTask(std::unique_ptr<TasksBase>{new ShutDownTask});
    }
}

void ThreadsPool::InternalAddTask(std::unique_ptr<TasksBase> a_task) {    
    m_tasksQueue.Enqueue(std::move(a_task));    
}

void ThreadsPool::Run() {
    while(true) {    
        try {             
            std::shared_ptr<TasksBase> t;
            m_tasksQueue.Dequeue(std::move(t)); 
            t->Act();

        } catch(const TaskExceptions&) {            
            break;

        } catch (...) { //user's task exceptions
            continue;
        }
        
    }       
}

} //threads