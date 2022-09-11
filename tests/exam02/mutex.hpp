#ifndef MUTEX_H
#define MUTEX_H

#include <pthread.h>
#include <unistd.h>

template <typename T>
class Mutex {
public:
    Mutex() = default;
    ~Mutex() = default;

    pthread_t& Create(T a_func);
    void Destroy(pthread_t& a_t);
    void Join(pthread_t& a_t);

};

#include "mutex.hxx"


#endif //MUTEX_H