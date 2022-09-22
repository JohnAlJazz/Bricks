#include "Threads.hpp"

namespace threads {

void Thread::Join() {
    if(::pthread_join(m_thread, 0) != 0) {
        switch (errno) {
            case EDEADLK:
                throw ThreadsErrors("Deadlock was detected\n");
                break;
            case ESRCH:
                throw ThreadsErrors("No thread with the Id thread was found\n");
                break;
            case EINVAL:
                assert("Invalid arrgument in pthread_create\n");
                break;            
            default:
                break;
        }
    }
    m_isJoinable = false;
}

Thread::~Thread() {
    if(m_isJoinable) {
        ::pthread_join(m_thread, 0);  //do what?
    };
}

} //threads