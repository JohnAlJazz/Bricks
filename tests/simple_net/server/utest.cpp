#include <assert.h>
#include <iostream>
#include <vector>
#include <memory>
#include <numeric>
#include <errno.h>

#include "TCPServerSocket.hpp"
#include "Socket.hpp"
#include "TCPClientSocket.hpp"
#include "TcpProtocol.hpp"



int main() {

    using namespace net;
    try{
        Server server(8080);                  
        Protocol proto;
        std::unique_ptr<Client> client = server.Accept(); 
        std::vector<double> dVec = proto.UnPack(client); 
        std::cout << dVec.size();  
        for(auto e : dVec) {
            std::cout << e;
        }                   
        std::cout << "\nserver main\n";        
    
    } catch(TCPSocketExceptions& e) {
        std::cout << e.what() << ", " << e.where() << "\n";
    }
}

