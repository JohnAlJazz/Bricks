#ifndef SOURCE_FACTORY_HPP
#define SOURCE_FACTORY_HPP

#include <memory>

#include <IStream.hpp>

namespace messenger {

class SourceFactory {
public:
    explicit SourceFactory(int a_source = 0);
    std::unique_ptr<IStream> Get();

private:
    int m_source;
};

} //messenger

#endif //SOURCE_FACTORY_HPP