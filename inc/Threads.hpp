#ifndef THREAD_HPP
#define THREAD_HPP

#include <pthread.h>

#include "ThreadsErrors.hpp"

namespace threads { 

class Thread {
public:
    using Func = void*(void*);

    template <typename T>
    Thread(Func& a_func, T* a_arg);
    Thread(const Thread&) = delete;
    Thread& operator=(const Thread&) = delete;
    ~Thread();

    void Join();
    void Detach(); // TODO

private:

    pthread_t m_thread;
    bool m_isJoinable;
};

} //threads

#include "inl/Threads.hxx"


#endif //THREAD_HPP