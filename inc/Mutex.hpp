#ifndef MUTEX_HPP
#define MUTEX_HPP

#include <pthread.h>

namespace threads { 

class Mutex {
public:

    Mutex();
    ~Mutex();
    Mutex(const Mutex&) = delete;
    Mutex& operator=(const Mutex&) = delete;

    void Lock();
    void TryLock(); //TODO
    void Unlock();

private:

    pthread_mutex_t m_mutex;
};

} //thread

#include "inl/Mutex.hxx"

#endif //MUTEX_HPP