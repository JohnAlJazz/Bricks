#include <iostream>

#include "IStream.hpp"

namespace messenger {

std::string Stdin::Read() {
    
    char stop;
    std::string line;
    std::string fullMsg;
    std::cout << "Enter your line\n\n";

    while(stop != '.') {
        std::getline(std::cin, line);
        fullMsg += line;
        fullMsg += '\n';        
        fullMsg += stop = std::getchar();        
    }
    return fullMsg;
}

File::File(std::ifstream& a_file) 
: m_file(a_file)
{}

std::string File::Read() {
    
    // std::string read;
    // std::string next;

    // while(!m_file.eof()) {
    //     m_file >> next;
    //     read += next; 
    //     read += " ";       
    // }
    // return read;
    return {};
}

} //messenger