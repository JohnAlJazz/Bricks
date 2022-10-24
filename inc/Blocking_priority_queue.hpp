#ifndef BLOCKING_PRIORITY_QUEUE_HPP
#define BLOCKING_PRIORITY_QUEUE_HPP

#include <deque>
#include <condition_variable>
#include <mutex>

namespace threads {

template <typename T>
class BlockingPriorityQueue {
public:
    explicit BlockingPriorityQueue(size_t a_capacity);
    void Push(const T& a_elem);
    void Pop(T& a_toRemove);
    void ProtectionPush(const T& a_elem);
    void ShutDown();

private:
    size_t m_capacity;
    std::deque<T> m_priorityQueue;
    std::mutex m_mutex;
    std::condition_variable m_notEmpty;
    std::condition_variable m_notFull;
    bool m_isShutDown;
};

#include "inl/Blocking_priority_queue.hxx"

} //threads

#endif //BLOCKING_PRIORITY_QUEUE_HPP