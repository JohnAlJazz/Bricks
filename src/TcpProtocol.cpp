#include <string>

#include "TcpProtocol.hpp"
#include "TCPClientSocket.hpp"



namespace net {

std::vector<unsigned char> Protocol::Pack(const std::vector<double>& a_vec) {
    
    std::vector<unsigned char> packedVec;
    auto vecSize = htobe64(a_vec.size()); 
    unsigned char* ptrSize = reinterpret_cast<unsigned char*>(&vecSize);
    for(size_t i = 0; i < sizeof(size_t); ++i) {
        packedVec.push_back(ptrSize[i]);
    }

    for(auto elem : a_vec) {
        double temp = htobe64(elem);        
        unsigned char* ptrChar = reinterpret_cast<unsigned char*>(&temp);
        for(size_t i = 0; i < sizeof(size_t); ++i) {
            packedVec.push_back(ptrChar[i]);
        }        
    }    
    return packedVec;
}


std::vector<double> Protocol::UnPack(std::unique_ptr<Client>& a_client) {

    std::vector<unsigned char> uscVec = a_client->Receive();

    double* nthDsize = reinterpret_cast<double*>(&uscVec[0]);       
    double dSize = be64toh(*nthDsize);
    size_t size = static_cast<size_t>(dSize);
    std::vector<double> dVector;
    for(size_t i = 0; i < uscVec.size(); ++i) {
        double* toDouble = reinterpret_cast<double*>(&uscVec[i * sizeof(double)]);
        double item = be64toh(*toDouble);
        dVector.push_back(item);
    } 
    while(dVector.size() < size) {
        uscVec = a_client->Receive();
        for(size_t i = 0; i < uscVec.size() / sizeof(double); ++i) {
            double* toDouble = reinterpret_cast<double*>(&uscVec[i * sizeof(double)]);
            double item = be64toh(*toDouble);
            dVector.push_back(item);
        }
    }       
    return dVector;
}





} //net