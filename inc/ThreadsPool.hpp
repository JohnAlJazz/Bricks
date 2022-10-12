#ifndef THREADSPOOL_HPP
#define THREADSPOOL_HPP

#include <memory>
#include <vector>
#include <thread>
#include <atomic>

#include "BlockingQueue.hpp"
#include "Task.hpp"

namespace threads {
    
class ThreadsPool {
public:
    explicit ThreadsPool(size_t a_numOfThreads = 1);
    ThreadsPool(const ThreadsPool&) = delete;
    ThreadsPool& operator=(const ThreadsPool&) = delete;
    ~ThreadsPool();

    void AddTask(std::unique_ptr<TasksBase> a_task);
    void AddTask(std::shared_ptr<TasksBase> a_task);

    template<typename FunctionObject>
    void AddTask(FunctionObject& a_task);

    void AddThreads(size_t numOfThreads);
    void RemoveThreads(size_t numOfThreads);         

    void ShutDown(); 
    void ShutDownImmediately();//TODO

private:
    void Run();    

private:
    void InternalAddTask(std::unique_ptr<TasksBase> a_task);

private:
    BlockingQueue<std::shared_ptr<TasksBase>> m_tasksQueue; 
    std::vector<std::thread> m_threads; 
    std::atomic_bool m_isDone;
};

} //threads

#include "inl/ThreadsPool.hxx"

#endif //THREADSPOOL_HPP