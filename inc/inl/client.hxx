using namespace net;

template <typename T>
T Client::Receive() {

    typename T::size_type sizeBufType; 
        
    if(recv(m_clientSocket.m_socket, &sizeBufType, sizeof(typename T::size_type), 0) <= 0) {
        throw TCPSocketExceptions("recv() 1 failed", "in client Receive()");
    }   
    T container(sizeBufType);     
    for(auto& elem : container) {
        if(recv(m_clientSocket.m_socket, &elem, sizeof(typename T::value_type), 0) <= 0) {
           throw TCPSocketExceptions("recv() 2 failed", "in client Receive()");  
        }        
    }
    return container;
}

template <typename T>
void Client::Send(T& a_buffer) {
    
    auto size = a_buffer.size();    
    if(send(m_clientSocket.m_socket, &size, sizeof(size), 0) < 0) {    
        throw TCPSocketExceptions("send() 1 failed", "in client Send()");
    }    
    for(auto e : a_buffer) {             
        if(send(m_clientSocket.m_socket, &e, sizeof(typename T::value_type), 0) < 0) {
            throw TCPSocketExceptions("send() 2 failed", "in client Send()");
        }        
    }
}

////////////////////////////////////////////////////////////////



// template <typename T>
// void Client::Send(T& a_buffer) {  

//     auto numOfElements = a_buffer.size(); 
//     if(send(m_clientSocket.m_socket, &numOfElements, sizeof(numOfElements), 0) < 0) {    
//         throw TCPSocketExceptions("send() 1 failed", "in client Send()");
//     }

//     const T buffer = a_buffer.data();
//     if(send(m_clientSocket.m_socket, buffer, numOfElements * sizeof(T), 0) < 0) {
//         throw TCPSocketExceptions("send() 2 failed", "in client Send()");
//     }
// }



// template <typename T>
// T Client::Receive() {

//     typename T::size_type numOfElements; 
        
//     if(recv(m_clientSocket.m_socket, &numOfElements, sizeof(typename T::size_type), 0) <= 0) {
//         throw TCPSocketExceptions("recv() 1 failed", "in client Receive()");
//     } 

//     auto bytesSize = numOfElements * sizeof(typename T::value_type);

//     T container(bytesSize);  
    
//     while(1){
//     if(recv(m_clientSocket.m_socket, container.data(), numOfElements * sizeof(typename T::value_type), 0) <= 0) {
//         throw TCPSocketExceptions("recv() 2 failed", "in client Receive()");  
//     }
//     return container;
// }
// }