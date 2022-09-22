#ifndef THREAD_HXX
#define THREAD_HXX

#include <cerrno>
#include <assert.h>

namespace threads {

template <typename T>
inline Thread::Thread(Func& a_func, T* a_arg)
: m_isJoinable(true)
{
    if(::pthread_create(&m_thread, 0, a_func, a_arg) < 0) {
        switch (errno) {
            case EAGAIN:
                throw ThreadsErrors("Lack the resources to create a thread\n");
                break;
            case ENOMEM:
                throw ThreadsErrors("Not enough memory to create a thread\n");
                break;
            case EINVAL:
                assert("invalid arrgument in pthread_create\n");
                break;
            
            default:
                break;
        }        
    }  
}

} // threads


#endif //THREAD_HXX