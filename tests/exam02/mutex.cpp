#include "mutex.hpp"


template <typename T>
pthread_t& Mutex<T>::Create(T a_func) {
    
    pthread_t thread;
    pthread_create(&thread, NULL, a_func, NULL) {
        pthread_join(thread, NULL);        
    }
    return thread;    
}



