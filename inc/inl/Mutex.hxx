#ifndef MUTEX_HXX
#define MUTEX_HXX

namespace threads {
//TODO => EXCEPTIONS
inline Mutex::Mutex()
{
    pthread_mutex_init(&m_mutex, NULL);
}

inline void Mutex::Lock() {
    pthread_mutex_lock(&m_mutex);
}

inline void Mutex::Unlock() {
    pthread_mutex_unlock(&m_mutex);
}

inline Mutex::~Mutex() {
    pthread_mutex_destroy(&m_mutex);
}

} // threads

#endif //MUTEX_HXX