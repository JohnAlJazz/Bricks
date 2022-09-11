#include "mutex.hpp"


template <typename T>
inline void Mutex<T>::Join(pthread_t& a_t) {
    pthread_join(a_t, NULL);
}

template <typename T>
inline void Mutex<T>::Destroy(pthread_t& a_t) {
    pthread_mutex_destroy(a_t, NULL);
}