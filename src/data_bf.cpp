#include "data_bf.hpp"
#include <stdio.h> /*printf*/

namespace bf {

DataBf::DataBf()
: m_dataList()
, m_itr(m_dataList.begin())
{}


void DataBf::operator++() {

    if(m_dataList.empty()) {
        m_dataList.push_back(0);
        return;
    }
    m_itr++;

    if(m_itr == m_dataList.end()) {
        m_itr--;
        m_dataList.push_back(0);
        m_itr++;       
    }     
}

void DataBf::operator--() {
    if(m_dataList.empty() || m_itr == m_dataList.begin()) {
        m_dataList.push_front(0);
        m_itr = m_dataList.begin();
        return;
    }
    --m_itr;
}


} //bf