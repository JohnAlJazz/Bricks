#ifndef BLOCKINGQ_HPP
#define BLOCKINGQ_HPP

#include <queue>
#include <mutex>
#include <iostream>
#include <unistd.h>
#include <cassert>
#include <chrono>

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
    void Dequeue(T& a_argPtr);

    size_t Size() const;  
    bool IsEmpty() const; 
   
private:

    std::queue<T> m_queue;
    Semaphore m_empty;
    Semaphore m_full;
    mutable std::mutex m_mutex; //mutex will change states even within a const function - Size()
    const bool m_isInfinite;
    
};

#include "inl/BlockingQueue.hxx"

} //threads

#endif //BLOCKINGQ_HPP