#ifndef THREADSPOOL_HPP
#define THREADSPOOL_HPP

#include <memory>
#include <vector>
#include <thread>
#include <atomic>
#include <functional>

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

    template<typename FuncObj>
    void AddTask(FuncObj& a_funcObj);
    
    void AddTask(std::function<void()> a_func);

    void AddThreads(size_t a_numOfThreads);
    void RemoveThreads(size_t a_numOfThreads);         

    void ShutDown(); 
    void ShutDownImmediately();    

private:
    void PushThreads(size_t a_numOfThreads);

private:
    void Run();    

private:
    void SendToInternalAddTask(size_t a_numOfThreads);
    void InternalAddTask(std::unique_ptr<TasksBase> a_task);

private:
    BlockingQueue<std::shared_ptr<TasksBase>> m_tasksQueue; 
    std::vector<std::thread> m_threads; 
    std::atomic_bool m_isDone;
    size_t m_numOfThreads;
};

} //threads

#include "inl/ThreadsPool.hxx"

#endif //THREADSPOOL_HPP