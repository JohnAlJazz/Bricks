#ifndef BLOCKINGQ_HPP
#define BLOCKINGQ_HPP

#include <queue>
#include <mutex>
#include <iostream>
#include <unistd.h>

#include "Semaphore.hpp"

namespace threads {

template<typename T>
class BlockingQueue {
public:

    BlockingQueue(size_t a_capacity);
    BlockingQueue();
    BlockingQueue(const BlockingQueue&) = delete;
    BlockingQueue& operator=(const BlockingQueue&) = delete;
    ~BlockingQueue() = default;

    void Enqueue(T a_arg);
    T Dequeue();

    size_t Size();   
   
private:

    std::queue<T> m_queue;
    Semaphore m_empty;
    Semaphore m_full;
    std::mutex m_mutex;
    bool m_isInfinite;
    
};

#include "inl/BlockingQueue.hxx"

} //threads

#endif //BLOCKINGQ_HPP