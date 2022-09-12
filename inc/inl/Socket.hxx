#include "Socket.hpp"

inline Socket::~Socket() {
    close(m_socket);
}