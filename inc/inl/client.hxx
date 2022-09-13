#include "TCPClientSocket.hpp"
#include <iostream>

using namespace net;

template <typename T>
T Client::Receive() {

    typename T::size_type sizeBuf = 0;
    if(recv(m_clientSocket.m_socket, &sizeBuf, sizeof(typename T::size_type), 0) <= 0) {
        throw "recv failed";
    }

    T container(sizeBuf);    

    for(auto& elem : container) {
        if(recv(m_clientSocket.m_socket, &elem, sizeof(typename T::value_type), 0) <= 0) {
           throw "recv failed";  
        }        
    }
    return container;
}

template <typename T>
void Client::Send(T& a_buffer) {
    auto size = a_buffer.size();
    send(m_clientSocket.m_socket, &size, sizeof(size), 0);

    for(auto e : a_buffer) {       
        
        if(send(m_clientSocket.m_socket, &e, sizeof(typename T::value_type), 0) < 0) {
            throw "send fail";
        }        
    }
}