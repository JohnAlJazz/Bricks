#ifndef THREADSPOOL_HPP
#define THREADSPOOL_HPP

#include <memory>
#include <vector>
#include <thread>

#include "BlockingQueue.hpp"
#include "Task.hpp"

namespace threads {
    
class ThreadsPool {
public:
    ThreadsPool();
    ThreadsPool(const ThreadsPool&) = delete;
    ThreadsPool& operator=(const ThreadsPool&) = delete;
    ~ThreadsPool() = default;

    void AddTask(std::unique_ptr<TasksBase> a_task);

    template<typename FunctionObjectT>
    void AddTask(FunctionObjectT a_task);         

    void Run(unsigned int a_numOfThreads);

private:
    void ThreadsLoop(); 

private:
    BlockingQueue<TasksBase*> m_tasksQueue; 
    std::vector<std::thread> m_threads;   
};

} //threads

#include "inl/ThreadsPool.hxx"

#endif //THREADSPOOL_HPP