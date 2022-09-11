#ifndef POINTER_H__
#define POINTER_H__


namespace pointer {


template <typename T>
class Pointer {
public:
    Pointer(T* a_pointer);
    ~Pointer();
    Pointer(const Pointer&) = default;
    Pointer& operator=(const Pointer&) = default;

    T& operator*();
    T* operator->();


private:
    T* m_pointer;
};


} //pointer


#include "inl/pointer.hxx"

#endif //POINTER_H__