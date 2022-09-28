#ifndef SEMAPHORE_HPP
#define SEMAPHORE_HPP

#include <semaphore.h>
#include <pthread.h>

namespace threads {

class Semaphore {
public:
    Semaphore(size_t a_counting);
    Semaphore(const Semaphore&) = delete;
    Semaphore& operator=(const Semaphore&) = delete;
    ~Semaphore();

    void Wait();
    void Post();  

private:  
    sem_t m_semaphore; 
};

#include "inl/Semaphore.hxx"

} //threads

#endif //SEMAPHORE_HPP