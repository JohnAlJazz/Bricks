#ifndef BLOCKING_PRIORITY_QUEUE_HXX
#define BLOCKING_PRIORITY_QUEUE_HXX

template <typename T>
BlockingPriorityQueue<T>::BlockingPriorityQueue(size_t a_capacity)
: m_capacity(a_capacity)
, m_priorityQueue()
, m_mutex()
, m_notEmpty()
, m_notFull()
, m_isShutDown(false)
{}

template <typename T>
void BlockingPriorityQueue<T>::Push(const T& a_elem) {

    std::unique_lock<std::mutex> guard(m_mutex);
    while(m_priorityQueue.size() == m_capacity && !m_isShutDown) {
        m_notFull.wait(guard);
    }     
    if(!m_isShutDown) {          
        m_priorityQueue.push_back(a_elem);
        m_notEmpty.notify_all();     
    }
}

template <typename T>
void BlockingPriorityQueue<T>::Pop(T& a_toRemove) {

    std::unique_lock<std::mutex> guard(m_mutex); 
    while(!m_priorityQueue.size() && !m_isShutDown) {           
        m_notEmpty.wait(guard);
    }    
    if(!m_isShutDown) { 
        a_toRemove = m_priorityQueue.front();
        m_priorityQueue.pop_front();
        m_notFull.notify_all();
    }
}

template <typename T>
void BlockingPriorityQueue<T>::ProtectionPush(const T& a_elem) {

    std::unique_lock<std::mutex> guard(m_mutex);
    while(m_priorityQueue.size() == m_capacity && !m_isShutDown) {
        m_notFull.wait(guard);
    }
    if(!m_isShutDown) { 
        m_priorityQueue.push_front(a_elem);
        m_notEmpty.notify_all();
    }
}

template <typename T>
void BlockingPriorityQueue<T>::ShutDown() {

    std::unique_lock<std::mutex> guard(m_mutex);
    m_isShutDown = true;
    m_notEmpty.notify_all(); //in case there's only popping (no signal to free them)
    m_notFull.notify_all(); //in case there's only pushing (no signal to free them)
}

#endif //BLOCKING_PRIORITY_QUEUE_HXX