#include "pointer.hpp"

using namespace pointer;

template <typename T>
Pointer<T>::Pointer(T* a_pointer) 
: m_pointer(a_pointer)
{}

template <typename T>
Pointer<T>::~Pointer() {
    delete m_pointer;
}

template <typename T>
T& Pointer<T>::operator*() {

    return *m_pointer;
}

template <typename T>
T* Pointer<T>::operator->() {
    *m_pointer;
}



