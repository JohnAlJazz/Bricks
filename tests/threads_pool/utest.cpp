#include <thread>
#include <queue>
#include <vector>
#include <chrono>
#include <mutex>
#include <functional>
#include <unistd.h>
#include <memory>

#include "mu_test.h"
#include "BlockingQueue.hpp"
#include "Semaphore.hpp"
#include "Task.hpp"
#include "ThreadsPool.hpp"


bool IsPrime(unsigned int a_num) {
    
    if(a_num < 2) {
        return false;
    }
    if(a_num == 2) {
        return true;
    }
    for(size_t i = 3; i < a_num; i += 2) {
        if(a_num % i == 0 || a_num % 2 == 0) {
            return false;
        }
    }
    return true;
}

bool IsSumDigits10(unsigned int a_num) {
    unsigned char sumDigits = 0;
    for ( ; a_num > 0 ; a_num /= 10) {
        sumDigits += (a_num % 10);
    }

    return sumDigits % 10 == 0;
}

bool IsPalyndrome(unsigned int a_num) {
    std::vector<unsigned char> asDigits;
    asDigits.reserve(20);

    for ( ; a_num > 0 ; a_num /= 10) {
        asDigits.push_back(a_num % 10);
    }

    size_t front = 0;
    size_t back = asDigits.size();
    while (front < back) {
        if (asDigits[front] != asDigits[back - 1]) {
            return false;
        }
        ++front;
        --back;
    }
    return true;
} 

void PrintPrimes(const std::vector<unsigned int>& a_primesVec) {

    std::cout << "\nPrimes:\n\n";
    for(const auto& e : a_primesVec) {
        std::cout << e << " is a prime number\n";
    }
    std::cout << "\n\n";
}

void PrintSummedTo10(const std::vector<unsigned int>& a_sumOfDigitsIs10Vec) {

    std::cout << "\nSUM:\n\n";
    for(const auto& e : a_sumOfDigitsIs10Vec) {
        std::cout << "sum of digits of  " << e << " is 10\n";
    }
    std::cout << "\n\n";
}

void PrintPalindromes(const std::vector<unsigned int>& a_PalindromeVec) {

    std::cout << "\nPalindromes:\n\n";
    for(const auto& e : a_PalindromeVec) {
        std::cout << e << " is a palindrome\n";
    }
    std::cout << "\n\n";
}

void StoragePrimes(unsigned int a_num) {

    std::vector<unsigned int> primesVec;
    for(size_t i = 0; i < a_num; ++i) {

        if(IsPrime(i)) {         
            primesVec.push_back(i);                                
        }
    }
    PrintPrimes(primesVec);
}

void StorageSummedTo10(unsigned int a_num) {

    std::vector<unsigned int> sumOfDigitsIs10Vec;
    for(size_t i = 0; i < a_num; ++i) {

        if(IsSumDigits10(i)) {         
            sumOfDigitsIs10Vec.push_back(i);                                
        }
    } 
    PrintSummedTo10(sumOfDigitsIs10Vec);  
}

void StoragePalindromes(unsigned int a_num) {

    std::vector<unsigned int> palindromeVec;
    for(size_t i = 0; i < a_num; ++i) {

        if(IsPalyndrome(i)) {         
            palindromeVec.push_back(i);                                
        }
    }
    PrintPalindromes(palindromeVec);   
}



BEGIN_TEST(threads_pool_unique_ptrs) 

using namespace threads;

    ThreadsPool tPool(3);   
    
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{StoragePalindromes, 1000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{StoragePrimes, 1000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{StorageSummedTo10, 1000}));
              
    
    ASSERT_PASS();
END_TEST

BEGIN_TEST(threads_pool_shut_down) 


using namespace threads;

    ThreadsPool tPool(3);   
    
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{StoragePalindromes, 10000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{StoragePrimes, 10000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{StorageSummedTo10, 10000}));
    tPool.ShutDown();              
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(threads_pool_shared_ptrs) 

using namespace threads;

    ThreadsPool tPool(4); 
    
    tPool.AddTask(std::shared_ptr<TasksBase>(new Task<unsigned int>{StoragePalindromes, 10'000})); 
    tPool.AddTask(std::shared_ptr<TasksBase>(new Task<unsigned int>{StoragePrimes, 10'000})); 
    tPool.AddTask(std::shared_ptr<TasksBase>(new Task<unsigned int>{StorageSummedTo10, 10'000})); 
    tPool.ShutDown();            
    
    ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)		
     
    // TEST(threads_pool_unique_ptrs)
    // TEST(threads_pool_shut_down) 
    TEST(threads_pool_shared_ptrs)    		

END_SUITE




