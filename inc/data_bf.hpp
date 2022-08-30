#ifndef DATA_BF_H__
#define DATA_BF_H__

#include "abstract_bf.hpp"
#include <string>
#include <list>

namespace bf {

class DataBf : public AbstractBf {
public:
    DataBf();    
    DataBf(const DataBf& a_code) = default;
    DataBf& operator=(const DataBf& a_code) = default;
    ~DataBf() = default;

    void operator++() override;
    void operator--() override;
    void operator++(int);
   
    void IncrementValue();
    void DecrementValue();
    void PrintValue() const noexcept;

private:
    std::list<int> m_dataList;
    std::list<int>::iterator m_itr; 
};


} //bf



#endif // DATA_BF_H__