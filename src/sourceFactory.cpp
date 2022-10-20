#include "sourceFactory.hpp"

namespace messenger {

SourceFactory::SourceFactory(int a_source)
: m_source(a_source)
{}

std::unique_ptr<IStream> SourceFactory::Get() {

    switch(m_source) {
        case 0:
            return std::make_unique<Stdin>();

        // case 1:                             
        //     return std::make_unique<File>();
                        
        default: 
            throw 111;            
    }
}

}//messenger