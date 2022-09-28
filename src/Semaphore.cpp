#include "Semaphore.hpp"

#include <iostream>

namespace threads {

Semaphore::Semaphore(size_t a_counting)
{
    sem_init(&m_semaphore, 0, a_counting); //exceptions    
}

void Semaphore::Wait() {
    sem_wait(&m_semaphore);    
}

void Semaphore::Post() {
    sem_post(&m_semaphore);    
}

Semaphore::~Semaphore() {
    sem_destroy(&m_semaphore);    
}



} //threads