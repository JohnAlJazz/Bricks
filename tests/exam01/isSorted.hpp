#ifndef IS_SORTED_H__
#define IS_SORTED_H__

template <typename C>
bool IsSorted(const C& a_container) {
    typedef typename C::const_iterator Itr;
    
    Itr it = a_container.begin();
    Itr end = a_container.end();
    while(it++ != end) {
        if(*it > *it + 1) {
            return false;
        }
    }
    return true;
}

#endif //IS_SORTED_H__