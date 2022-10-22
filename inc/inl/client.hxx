#include "TCPClientSocket.hpp"

using namespace net;



// // template <typename T>
// inline const std::vector<unsigned char> Receive() {

//     // typename T::size_type sizeBufType;
//     std::vector<unsigned char> buffer(1000);    
//     size_t receivedBytes = 0;
    
        
//     if(recv(m_clientSocket.m_socket, &buffer, sizeof(buffer), 0) <= 0) {
//         throw TCPSocketExceptions("recv() 1 failed", "in client Receive()");
//     }
//     receivedBytes = buffer.size();    
//     return buffer;
// }

// // template <typename T>
// inline void Client::Send(const std::vector<unsigned char>& a_buffer) {

//     // if((sentBytes = send(m_clientSocket.m_socket, &a_buffer, sizeof(a_buffer), 0)) < 0) {    
//     //     throw TCPSocketExceptions("send() 1 failed", "in client Send()");
//     // }
//     size_t bytesToSend = a_buffer.size();
//     ssize_t sentBytes = 0;   

//     while(bytesToSend > 0) {             
//         if((sentBytes = send(m_clientSocket.m_socket, &a_buffer, sizeof(a_buffer), 0)) < 0) {    
//             throw TCPSocketExceptions("send() failed", "in client Send()");
//         }
//         bytesToSend -= sentBytes; 
//     }    
// }

////////////////////////////////////////////////////////////////

// inline void Check(int a_fd, int a_res) {
//     if(a_res == 0) {
//         close(a_fd);
//         throw TCPSocketExceptions("recv()", "connection failed");
//     }
//     else if(a_res == -1){
//         throw TCPSocketExceptions("recv()", "errno EAGAIN\n");
//     }
// }

// template <typename T>
// void Client::Send(T& a_buffer) {  

//     // auto size = a_buffer.size();  
//     // int res = 0;
//     // send(m_clientSocket.m_socket, &size, sizeof(size), 0);
         

//     send(m_clientSocket.m_socket, a_buffer.data(), size * sizeof(typename T::value_type), 0);
    
// }



// template <typename T>
// T Client::Receive() {

//     typename T::size_type bufferSize = 0;    
//     int res = 0;
//     res = recv(m_clientSocket.m_socket, &bufferSize, sizeof(bufferSize), 0);
    
                      

//     T container(bufferSize);
            
    
//     return container;
// }