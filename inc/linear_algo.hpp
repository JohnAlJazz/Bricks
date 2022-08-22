#ifndef LINEAR_ALGO_H__
#define LINEAR_ALGO_H__
#include <iterator>
#include <iostream>
#include <vector>
#include <time.h>


template <typename C>
void Print(C const& a_container) {
    typedef typename C::const_iterator Iter;
    Iter begin = a_container.begin();
    Iter end = a_container.end();
    if(begin == end) {
        std::cout << "{}" << '\n';
        return;
    }
    while(begin != end - 1) {
        std::cout << *begin++ << ", ";
    }
    std::cout << *begin << '\n';    
}


std::vector<double> CreateChaos(int a_number) {
    srand(time(NULL));
    std::vector<double> vec;
    for(int i = 0; i < a_number; ++i) {
        double randD = ((double) rand() * 10 / (double)RAND_MAX);
        vec.push_back(randD);
    }    
    return vec;
}

template <typename T>
T Sum(std::vector<T> const& a_vec) {
    typedef typename std::vector<T>::const_iterator Iter;
    Iter begin = a_vec.begin();
    Iter end = a_vec.end();
    T sum = 0;
    while(begin != end) {
        sum += *begin++;
    }
    return sum;
}

template <typename C>
int CountAboveAverage(C const& a_container) {
    typedef typename C::const_iterator Iter;
    Iter begin = a_container.begin();
    Iter end = a_container.end();
    int sum = 0, aboveAvg = 0, numOfElements = 0, avg = 0;
    while(begin != end) {
        sum += *begin++;
        ++numOfElements;
    }
    avg = sum / numOfElements;
    begin = a_container.begin();
    while(begin != end) {
        if(*begin++ > avg) {
            ++aboveAvg;
        }
    }
    return aboveAvg;    
}

std::vector<int>& OddsOut(std::vector<int>& a_vec) {
    typedef typename std::vector<int>::const_iterator Itr;
    Itr begin = a_vec.begin();   
    Itr end = a_vec.end();  
    while(begin != end) {
        if(*begin % 2 != 0) {                      
            a_vec.erase(begin); 
            end = a_vec.end();                                
        }
        else {
            ++begin;
        }       
    }   
    return a_vec;
}    


template <typename T>
class MinMax {
public:
    MinMax(T a_min, T a_max) : m_min{a_min} , m_max{a_max} {}
    const T m_min;
    const T m_max;
};


template <typename C> 
MinMax<typename C::value_type> Extreme(C const& a_container) {
    typedef typename C::const_iterator Iter;
    Iter begin = a_container.begin();
    Iter end = a_container.end();
    Iter max = begin != end ? begin++ : begin; 
    Iter min = max;
    while(begin != end) {
        if(*begin >= *max) {
            max = begin;
        }
        if(*begin <= *min) {
            min = begin;
        }
        begin++;
    }   
    MinMax<typename C::value_type> m(*min, *max);
    return m;
}





#endif //