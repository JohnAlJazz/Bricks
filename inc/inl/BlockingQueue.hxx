#ifndef BLOCKINGQ_HXX
#define BLOCKINGQ_HXX


template<typename T>
BlockingQueue<T>::BlockingQueue(size_t a_capacity)
: m_deque()
, m_empty(a_capacity) 
, m_full(0)
, m_isInfinite(false)
{}

template <typename T>
BlockingQueue<T>::BlockingQueue()
: m_deque()
, m_empty(0) 
, m_full(0)
, m_isInfinite(true)
{}

template <typename T>
void BlockingQueue<T>::Enqueue(T& a_arg) {       
    InternalEnqueue(a_arg);     
}

template <typename T>
void BlockingQueue<T>::Enqueue(T&& a_arg) {     
    InternalEnqueue(a_arg);       
}

template <typename T>
void BlockingQueue<T>::InternalEnqueue(T& a_arg) {

    if(!m_isInfinite) {  
        m_empty.Wait();  
    }
    try {
        std::lock_guard<std::mutex> guard(m_mutex);  
        #ifdef TIME_STAMP
        a_arg.ingress = std::chrono::steady_clock::now(); 
        #endif     
        m_deque.push_back(a_arg); 

    } catch(...) {
        m_empty.Post(); //if push failed, number of empty slots remains the same, therefore Post() is needed
        throw;
    }
    m_full.Post(); 
}

template <typename T>
void BlockingQueue<T>::Dequeue(T& a_argRef) {
    
    m_full.Wait();
    try {
        std::lock_guard<std::mutex> guard(m_mutex);         
        a_argRef = m_deque.front();
        #ifdef TIME_STAMP
        a_arg.egress = std::chrono::system_clock::now(); 
        #endif
        m_deque.pop_front(); 
        if(m_isInfinite) {
            m_empty.Post();
        }          
    } catch(...) {
        m_full.Post();
        throw;
    }      
}

template <typename T>
void BlockingQueue<T>::ProtectionEnqueue(T a_arg) {
    
    try {
        std::lock_guard<std::mutex> guard(m_mutex);              
        m_deque.push_front(a_arg); 

    } catch(...) {
        m_empty.Post(); 
        throw;
    }
    m_full.Post();
}

template <typename T> 
size_t BlockingQueue<T>::Size() const {
    std::lock_guard<std::mutex> guard(m_mutex);
    return m_deque.size();
}

template <typename T>
bool BlockingQueue<T>::IsEmpty() const {
    return !Size();
}

#endif //BLOCKINGQ_HXX