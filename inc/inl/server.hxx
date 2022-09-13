#include "server.hpp"


// template <typename T>
// inline void Server::Recieve() {
//     m_serverSocket.Recieve();   
// }
using namespace net;

template <typename T>
T Server::Receive() {

    typename T::size_type sizeBuf = 0;
    if(recv(m_clientSocket, &sizeBuf, sizeof(sizeBuf), 0) <= 0) {
        throw "recv failed";
    }

    T container(sizeBuf);    
    typename T::value_type element;

    for(auto& elem : container) {
        if(recv(m_clientSocket, &elem, sizeof(element), 0) <= 0) {
           throw "recv failed";  
        }        
    }
    return container;
}

template <typename T>
void Server::Send(T* a_buffer) {

    auto size = a_buffer->size();

    send(m_clientSocket, &size, sizeof(size), 0);
    for(auto& elem : *a_buffer) {
        if(send(m_clientSocket, &elem, sizeof(typename T::value_type), 0) < 0) {
            throw "couldn't send from server";
        }
    }
}