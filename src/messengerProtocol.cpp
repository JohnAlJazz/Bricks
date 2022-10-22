#include "messengerProtocol.hpp"

namespace messenger {

std::vector<unsigned char> Protocol::Pack(std::string& a_msg) {
    
    std::vector<unsigned char> packedVec;     
    size_t size = a_msg.length();
    unsigned char* ptrSize = reinterpret_cast<unsigned char*>(&size);
    
    for(size_t i = 0; i < sizeof(size_t); ++i) {
        packedVec.push_back(ptrSize[i]);
    }

    for(auto elem : a_msg) {
        packedVec.push_back(elem);               
    }     
    return packedVec;
}

std::string Protocol::UnPack(std::unique_ptr<net::Client> a_client) {

    std::vector<unsigned char> uscVec = a_client->Receive();
    size_t* nthDsize = reinterpret_cast<size_t*>(&uscVec[0]);       
    std::string s;    
    size_t i = sizeof(size_t);
    if(uscVec.size() > sizeof(size_t)) {
        for(; i < uscVec.size(); ++i) {
            s.push_back(uscVec[i]);       
        }
    }
     
    while(uscVec.size() < *nthDsize) {
        uscVec = a_client->Receive();

        for(; i < uscVec.size(); ++i) {
            s.push_back(uscVec[i]);
        } 
    }     
    return s;
}

} //messenger


    // double dSize = be64toh(*nthDsize);
    // size_t size = static_cast<size_t>(dSize);