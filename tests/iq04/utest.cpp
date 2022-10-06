#include "mu_test.h"

#include <assert.h>
#include <set>
#include <thread>
#include <chrono>
#include <vector>
#include <numeric> //iota
#include <mutex>
#include <condition_variable>


bool Find(int arr[], size_t size, int x) {
    
    for(size_t i = 0; i < size; ++i) {
        if(arr[i] == x) {
            return true;
        }
    }
    return false;
}

void Sort012(int arr[], size_t size) {

    size_t zeros = 0;
    size_t ones = 0;
    for(size_t i = 0; i < size; ++i) {
        if(arr[i] == 0) {
            ++zeros;
        }
        else if(arr[i] == 1) {
            ++ones;
        }
    }
    for(size_t i = 0; i < zeros; ++i) {
        arr[i] = 0;
    }
    for(size_t i = zeros; i < zeros + ones; ++i) {
        arr[i] = 1;
    }
    for(size_t i = zeros + ones; i < size; ++i) {
        arr[i] = 2;
    }
}

bool Is2ElementsEqualSum(int arr[], size_t size, int sum) {
    int* end = &arr[size - 1];
    int* begin = arr;
    while(*begin + *end > sum) {
        --end;
    }
    while(*begin + *end < sum) {
        ++begin;
    }
    if(*begin + *end == sum) {
        return true;
    }
    return false;
}

std::pair<int,int> UnsortedArraySumOfTwoElements(int arr[], size_t size, int sum) {
    std::set<int> set{arr, &arr[size]};
    std::set<int>::iterator it = set.begin();
    std::set<int>::iterator end = set.end();
    while(*it + *end > sum) {
        --end;
    }
    while(*it + *end < sum) {
        ++it;
    }
    int firstIndex = 0;
    int secondIndex = 0;
    if(*it + *end == sum) {
        for(size_t i = 0; i < size; ++i) {
            if(arr[i] == *it) {
                firstIndex = i;
            }
            if(arr[i] == *end) {
                secondIndex = i;
            }
        }
    }
    return std::make_pair(firstIndex,secondIndex);    
}

void ReverseBits1(int& a_int) {
    for(int i = 0, j = 7; i < 4; ++i, --j) {
        if((a_int & (1<<j) && !(a_int & (1<<i))) || (!(a_int & (1<<j)) && (a_int & (1<<i)))) {  
            a_int ^= 1<<j;
            a_int ^= 1<<i;
        }       
    }
}

int Majority(long a_long) {
    size_t ones = 0;
    for(size_t i = 0; i < sizeof(long) * 8; ++i) {
        if(a_long & (1L<<i)) {
            ++ones;            
        }       
    }  
    std::cout << "ones: " << ones << '\n';  
    if(ones > (sizeof(long) * 8) / 2) {
        return 1;
    }
    return 0;
}

void printBitsLong(long l) {
    for(int i = 63; i >= 0; --i) {
        l & (1L<<i) ? std::cout << "1" : std::cout << "0";
    }
}


bool notify = false;
std::vector<int> vGlobal;

void PrintEven(int a_from, int a_upTo) {

    for(int i = a_from; i < a_upTo; ++i) {
        if((!(i & 1)) && !notify) {
            std::cout << i << ", ";
            vGlobal.push_back(i);
            notify = true;      
        } 
        if(notify){
            std::this_thread::sleep_for(std::chrono::milliseconds(2));        
        }
    }
}

void PrintOdd(int a_from, int a_upTo) {

    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    for(int i = a_from; i < a_upTo; ++i) {
        if(i & 1 && notify) {
            std::cout << i << ", ";
            vGlobal.push_back(i);
            notify = false;
        } 
        if(!notify){
            std::this_thread::sleep_for(std::chrono::milliseconds(2));        
        }              
    }
}

int g;
std::mutex m;
std::condition_variable cv;
std::vector<int> checkVector;

//ignore single responsibilty
void PrintAndNotify() {

    checkVector.push_back(g);
    std::cout << g++ << ", ";
    cv.notify_one();
}

void PrintEvenCV(int a_upTo) {

    while(g < a_upTo) {
        
        std::unique_lock<std::mutex> guard(m);
        cv.wait(guard, [] {return g & 1 ? false : true;});
        PrintAndNotify();  
    }    
}

void PrintOddCV(int a_upTo) {

    
    while(g < a_upTo) {
        std::unique_lock<std::mutex> guard(m);
        cv.wait(guard, [] {return !(g & 1) ? false : true;});
        PrintAndNotify();        
    }
}

BEGIN_TEST(find_n_comparisons)
    int arr[] = {1,2,3,4,5,6,7,8,9};
    bool res = Find(arr, 9, 5); 
    bool res2 = Find(arr, 9, 0);   
    ASSERT_THAT(res == true && res2 == false);
END_TEST


BEGIN_TEST(sort012)
    int arr[] = {0,2,2,1,1,2,0,1,2,0,1,2,0};   
    Sort012(arr, 13);  
    for(int i = 0; i < 13; ++ i) {
        std::cout << arr[i] << ", ";
    } 
    ASSERT_PASS();
END_TEST


BEGIN_TEST(sumOf2)
    int arr[] = {-3,-1,0,1,3,5,7,9,12};  
    bool res = Is2ElementsEqualSum(arr, 9, 15);    
    ASSERT_THAT(res == true);
END_TEST


BEGIN_TEST(sumOf2UnSortedArray)
    int arr[] = {3,5,8,1,0,6,9,4,5,11};  
    std::pair<int,int> p = UnsortedArraySumOfTwoElements(arr, 10, 14); 
    std::cout << p.first << ", " << p.second << '\n';   
    ASSERT_PASS();
END_TEST


BEGIN_TEST(reverse_bits_1)
    int x = 177;
    ReverseBits1(x);   
    ASSERT_EQUAL(x, 141);
END_TEST


BEGIN_TEST(majority)
    long x = 1, y = 999999999999999;
    int res = Majority(x); 
    int res2 = Majority(y);   
    printBitsLong(y);    
    ASSERT_THAT(res == 0 && res2 == 1);
END_TEST


BEGIN_TEST(two_threads_even_odd)

    std::thread t1(PrintEven, 0, 100);
    std::thread t2(PrintOdd, 0, 100);

    std::vector<int> vLocal(100);
    std::iota(vLocal.begin(), vLocal.end(), 0);

    t1.join();
    t2.join();

    ASSERT_THAT(vLocal == vGlobal);
END_TEST

BEGIN_TEST(two_threads_even_odd_usingCV)

    std::thread t1(PrintEvenCV, 100);
    std::thread t2(PrintOddCV, 100); 
    std::vector<int> v(101);
    std::iota(v.begin(), v.end(), 0); 

    t1.join();
    t2.join();
    
    ASSERT_THAT(v == checkVector);
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
    // TEST(find_n_comparisons)
    // TEST(sort012)
    // TEST(sumOf2)
    // TEST(sumOf2UnSortedArray)
    // TEST(reverse_bits_1)
    // TEST(majority)
    // TEST(two_threads_even_odd)
    TEST(two_threads_even_odd_usingCV)
    
END_SUITE








///////



/* int g;
std::mutex m;

void PrintOddUsingMutex(int a_from, int a_upTo) {

    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    for(int i = a_from; i < a_upTo; ++i) {
        std::unique_lock<std::mutex> guard(m);
        if(g & 1) {
            std::cout << g++ << ", ";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        m.unlock();
    } 
}

void PrintEvenUsingMutex(int a_from, int a_upTo) {

    for(int i = a_from; i < a_upTo; ++i) {
        std::unique_lock<std::mutex> guard(m);
        if(!(g & 1)) {
            std::cout << g++ << ", ";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        m.unlock();
    } 
} */

