using namespace net;

// template <typename T>
// T Client::Receive() {

//     typename T::size_type sizeBufType; 
        
//     if(recv(m_clientSocket.m_socket, &sizeBufType, sizeof(typename T::size_type), 0) <= 0) {
//         throw TCPSocketExceptions("recv() 1 failed", "in client Receive()");
//     }   
//     T container(sizeBufType);  
    
//     for(auto& elem : container) {
//         if(recv(m_clientSocket.m_socket, &elem, sizeof(typename T::value_type), 0) <= 0) {
//            throw TCPSocketExceptions("recv() 2 failed", "in client Receive()");  
//         }        
//     }
//     return container;
// }

// template <typename T>
// void Client::Send(T& a_buffer) {

//     auto size = a_buffer.size();    
//     if(send(m_clientSocket.m_socket, &size, sizeof(size), 0) < 0) {    
//         throw TCPSocketExceptions("send() 1 failed", "in client Send()");
//     }

//     for(auto e : a_buffer) {             
//         if(send(m_clientSocket.m_socket, &e, sizeof(typename T::value_type), 0) < 0) {
//             throw TCPSocketExceptions("send() 2 failed", "in client Send()");
//         }        
//     }
// }

////////////////////////////////////////////////////////////////


template <typename T>
void Client::Send(T& a_buffer) {  


    auto size = a_buffer.size();  
    if(send(m_clientSocket.m_socket, &size, sizeof(size), 0) < 0) {
        throw TCPSocketExceptions("send() 2 failed", "in client Send()");
    }

    if(send(m_clientSocket.m_socket, &a_buffer, size * sizeof(typename T::value_type), 0) < 0) {
        throw TCPSocketExceptions("send() 2 failed", "in client Send()");
    } 
}

template <typename T>
T Client::Receive() {

    typename T::size_type bufferSize = 0;    
    
    if(recv(m_clientSocket.m_socket, &bufferSize, sizeof(bufferSize), 0) < 0) {
    throw TCPSocketExceptions("recv() 2 failed", "in client Receive()");           
    }

    T container(bufferSize);

    if(recv(m_clientSocket.m_socket, &container, bufferSize * sizeof(typename T::value_type), 0) < 0) {
        throw TCPSocketExceptions("recv() 2 failed", "in client Receive()");           
    }
    return container;
}