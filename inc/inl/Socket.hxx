#include "Socket.hpp"

using namespace net;

// template<typename T>
// inline void Socket::Recieve(int a_fd, T* a_buffer, int a_flag) {
//     size_t bufLen = sizeof(a_buffer);
//     int readBytes = recv(a_fd, a_buffer, bufLen, a_flag);    
//     if(readBytes == 0) {
//         close(a_fd);
//         throw "recv fail";
//     }
//     else if(readBytes < 0) {
//         throw "read fail";
//     }    
// }