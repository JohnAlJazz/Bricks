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

void Primes(unsigned int a_num) {

    std::vector<unsigned int> primesVec;
    for(size_t i = 0; i < a_num; ++i) {

        if(IsPrime(i)) {         
            primesVec.push_back(i);                                
        }
    }
    PrintPrimes(primesVec);
}

void SummedTo10(unsigned int a_num) {

    std::vector<unsigned int> sumOfDigitsIs10Vec;
    for(size_t i = 0; i < a_num; ++i) {

        if(IsSumDigits10(i)) {         
            sumOfDigitsIs10Vec.push_back(i);                                
        }
    } 
    PrintSummedTo10(sumOfDigitsIs10Vec);  
}

void Palindromes(unsigned int a_num) {

    std::vector<unsigned int> palindromeVec;
    for(size_t i = 0; i < a_num; ++i) {

        if(IsPalyndrome(i)) {         
            palindromeVec.push_back(i);                                
        }
    }
    PrintPalindromes(palindromeVec);   
}

////////////////////////////////////////////////////////////////////////

BEGIN_TEST(threads_pool_unique_ptrs_to_tasks) 

using namespace threads;

    ThreadsPool tPool(3);   
    
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{Palindromes, 1000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{Primes, 1000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{SummedTo10, 1000}));              
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(threads_pool_shared_ptrs_to_tasks) 

using namespace threads;

    ThreadsPool tPool(4);     
                    
    tPool.AddTask(std::shared_ptr<TasksBase>(new Task<unsigned int>{Palindromes, 10'000}));  //using shared_ptr
    tPool.AddTask(std::make_shared<Task<unsigned int>>(Palindromes, 10'000)); //using make_shared
    tPool.AddTask(std::shared_ptr<TasksBase>(new Task<unsigned int>{Primes, 10'000})); 
    tPool.AddTask(std::shared_ptr<TasksBase>(new Task<unsigned int>{SummedTo10, 10'000}));        
                 
    ASSERT_PASS();    
END_TEST

    
BEGIN_TEST(threads_pool_template_add_tasks) 

using namespace threads;  

    struct Foo {  
        void operator()()
        {std::cout << "Testing AddTsk<> Function object\n";}
    };

    ThreadsPool tPool; 
    Foo f;
    FunctionObject<Foo>funcObj(f);    
    tPool.AddTask<FunctionObject<Foo>>(funcObj); 
    tPool.ShutDown();    
               
    ASSERT_PASS();    
END_TEST


BEGIN_TEST(threads_pool_std_function1) 

using namespace threads;  

    ThreadsPool tPool;  
    std::function<void()> func = []() {
        std::cout << "Testing AddTask(std::function)\n";
    };   
    tPool.AddTask(func);
    tPool.ShutDown();        
               
    ASSERT_PASS();    
END_TEST


void palindromes() {
    Palindromes(100'000);
}

BEGIN_TEST(threads_pool_std_function2) 

using namespace threads;      

    ThreadsPool tPool;  
    std::function<void()> func = palindromes;  
    tPool.AddTask(func);
    tPool.ShutDown();        
               
    ASSERT_PASS();    
END_TEST


BEGIN_TEST(threads_pool_remove_threads) 

using namespace threads;

    ThreadsPool tPool(10);   
    
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{Palindromes, 1000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{Primes, 1000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{SummedTo10, 1000}));

    tPool.RemoveThreads(12);              
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(threads_pool_add_threads) 

using namespace threads;

    ThreadsPool tPool(4); 
    
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{Palindromes, 1000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{Primes, 1000}));
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{SummedTo10, 1000}));
    
    tPool.RemoveThreads(4);
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{Palindromes, 1000}));

    sleep(3);
    tPool.AddThreads(1);              
    tPool.RemoveThreads(1);

    ASSERT_PASS();
END_TEST


BEGIN_TEST(threads_pool_shut_down) 

using namespace threads;

    ThreadsPool tPool(3);       
             
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{Palindromes, 1000}));             
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{Primes, 1000})); 
    tPool.AddTask(std::unique_ptr<TasksBase>(new Task<unsigned int>{SummedTo10, 1000}));    
    
    tPool.ShutDown();             
    
    ASSERT_PASS();
END_TEST


BEGIN_TEST(threads_pool_shut_down_immediately) 

using namespace threads;

    ThreadsPool tPool(4); 
    
    tPool.AddTask(std::shared_ptr<TasksBase>(new Task<unsigned int>{Primes, 10'000})); 
    tPool.AddTask(std::shared_ptr<TasksBase>(new Task<unsigned int>{Palindromes, 10'000})); 
    tPool.AddTask(std::shared_ptr<TasksBase>(new Task<unsigned int>{SummedTo10, 10'000})); 
    
    tPool.ShutDownImmediately();           
    
    ASSERT_PASS();
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)		
     
    // TEST(threads_pool_unique_ptrs_to_tasks)
    // TEST(threads_pool_shared_ptrs_to_tasks)
    // TEST(threads_pool_template_add_tasks)
    TEST(threads_pool_std_function1)
    // TEST(threads_pool_std_function2)
    // TEST(threads_pool_remove_threads)
    // TEST(threads_pool_add_threads)
    // TEST(threads_pool_shut_down)         	
    // TEST(threads_pool_shut_down_immediately)	    

END_SUITE




