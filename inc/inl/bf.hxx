#ifndef BF_H__
#define BF_H__


using namespace bf;

inline void DataBf::IncrementValue() {
    ++*m_itr;
}

inline void DataBf::DecrementValue() {
    --*m_itr;
}

inline void DataBf::PrintValue() const noexcept{
    printf("%c\n", *m_itr);
}


void CodeBf::operator++() {
    m_itr++;
}    

void CodeBf::operator--() {
    m_itr--;    
}

const char& CodeBf::at() const noexcept {
    return *m_itr;
}

size_t CodeBf::Size() const noexcept {
    return m_code.size();
}

#endif //BF_H__