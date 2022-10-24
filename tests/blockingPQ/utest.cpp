#include "mu_test.h"

#include <thread>
#include <vector>
#include <unistd.h>

#include "Blocking_priority_queue.hpp"

using namespace threads; 

void Push(BlockingPriorityQueue<int>& a_bpq) {
    for(int i = 0; i < 500; ++i) {        
        a_bpq.Push(1);                   
    }  
}

void Pop(BlockingPriorityQueue<int>& a_bpq) {           
    int rmv;      
    for(int i = 0; i < 500; ++i) {  
        a_bpq.Pop(rmv);                    
    }    
}

///////////////////////////////////////////////

BEGIN_TEST(two_threads_pushing_2_threads_popping) 

    BlockingPriorityQueue<int> bpq(1000);

    std::vector<std::thread> threads; 

    threads.push_back(std::thread(Push, std::ref(bpq)));
    threads.push_back(std::thread(Push, std::ref(bpq)));
    threads.push_back(std::thread(Pop, std::ref(bpq))); 
    threads.push_back(std::thread(Pop, std::ref(bpq)));  
    
    for(auto &e : threads) {
        e.join();
    }

    ASSERT_PASS();    
END_TEST


BEGIN_TEST(two_threads_pushing_2_threads_popping_shut_down) 

    BlockingPriorityQueue<int> bpq(1000);

    std::vector<std::thread> threads; 

    threads.push_back(std::thread(Push, std::ref(bpq)));
    threads.push_back(std::thread(Push, std::ref(bpq)));
    threads.push_back(std::thread(Pop, std::ref(bpq))); 
    threads.push_back(std::thread(Pop, std::ref(bpq)));  
         
    bpq.ShutDown();

    for(auto &e : threads) {
        e.join();
    }

    ASSERT_PASS();    
END_TEST


BEGIN_SUITE(Its what you learn after you know it all that counts)
		
    // TEST(two_threads_pushing_2_threads_popping)
    TEST(two_threads_pushing_2_threads_popping_shut_down)
    

END_SUITE
