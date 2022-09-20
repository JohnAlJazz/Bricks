#include "TCPServerAsync.hpp"

inline int AsyncServer::GetSocket() {
    return m_serverSocket.m_socket;
}
