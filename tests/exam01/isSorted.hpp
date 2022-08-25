#ifndef IS_SORTED_H__
#define IS_SORTED_H__
#include <stdio.h>

template <typename C>
bool IsSorted(const C& a_container) {
    typedef typename C::const_iterator Itr;
    
    Itr it = a_container.begin();
    Itr end = a_container.end();
    while(it++ != end) {
        printf("%d %d\n", *it, *(it ++));
        if(*it > *(it ++)) {           
            return false;
        }
        // it++;
    }
    printf("HERE\n");
    return true;
}

#endif //IS_SORTED_H__