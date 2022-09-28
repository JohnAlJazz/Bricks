#ifndef BLOCKINGQ_HXX
#define BLOCKINGQ_HXX


template<typename T>
BlockingQueue<T>::BlockingQueue(size_t a_capacity)
: m_queue()
, m_empty(a_capacity) 
, m_full(0)
, m_isInfinite(false)
{}

template<typename T>
BlockingQueue<T>::BlockingQueue()
: m_queue()
, m_empty(0) 
, m_full(0)
, m_isInfinite(true)
{}

template <typename T>
void BlockingQueue<T>::Enqueue(T a_arg) {  
    if(! m_isInfinite) {  
        m_empty.Wait();  
    }
    std::lock_guard<std::mutex> guard(m_mutex);        
    m_queue.push(a_arg);          
    m_full.Post();       
}

template <typename T>
T BlockingQueue<T>::Dequeue() {
    
    m_full.Wait();
    std::lock_guard<std::mutex> guard(m_mutex); 
    T elem = m_queue.front();
    m_queue.pop(); 
    m_empty.Post();
    return elem;     
}

template <typename T>
size_t BlockingQueue<T>::Size() {
    return m_queue.size();
}


#endif //BLOCKINGQ_HXX