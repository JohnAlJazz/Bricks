#ifndef ABSTRACT_BF_H__
#define ABSTRACT_BF_H__

namespace bf {

class AbstractBf {
public:
    virtual void operator++() = 0;
    virtual void operator--() = 0;
    ~AbstractBf() = default;   


protected:
    AbstractBf() = default;
    AbstractBf(const AbstractBf& a_other) = default;
    AbstractBf& operator=(const AbstractBf& a_other) = default;
};

}
#endif // ABSTRACT_BF_H__