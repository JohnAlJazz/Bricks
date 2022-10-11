#ifndef BLOCKINGQ_HXX
#define BLOCKINGQ_HXX


template<typename T>
BlockingQueue<T>::BlockingQueue(size_t a_capacity)
: m_queue()
, m_empty(a_capacity) 
, m_full(0)
, m_isInfinite(false)
{}

template <typename T>
BlockingQueue<T>::BlockingQueue()
: m_queue()
, m_empty(0) 
, m_full(0)
, m_isInfinite(true)
{}

template <typename T>
void BlockingQueue<T>::Enqueue(T a_arg) {  

    if(!m_isInfinite) {  
        m_empty.Wait();  
    }
    try {
        std::lock_guard<std::mutex> guard(m_mutex);  
        #ifdef TIME_STAMP
        a_arg.ingress = std::chrono::steady_clock::now(); 
        #endif     
        m_queue.push(a_arg); 

    } catch(...) {
        m_empty.Post(); //if push failed, there is the same number of empty slots, therefore Post() is needed
        throw;
    }
    m_full.Post();    
}

template <typename T>
void BlockingQueue<T>::Dequeue(T& a_arg) {
    
    m_full.Wait();
    try {
        std::lock_guard<std::mutex> guard(m_mutex);         
        a_arg = m_queue.front();
        #ifdef TIME_STAMP
        a_arg.egress = std::chrono::system_clock::now(); 
        #endif
        m_queue.pop(); 
        if(m_isInfinite) {
            m_empty.Post();
        }          
    } catch(...) {
        m_full.Post();
        throw;
    }      
}

template <typename T>
size_t BlockingQueue<T>::Size() const {
    std::lock_guard<std::mutex> guard(m_mutex);
    return m_queue.size();
}

template <typename T>
bool BlockingQueue<T>::IsEmpty() const {
    return !Size();
}

#endif //BLOCKINGQ_HXX