#include "mu_test.h"

#include <thread>
#include <queue>
#include <vector>
#include <chrono>
#include <mutex>
#include <functional>
#include <unistd.h>
#include <memory>

#include "BlockingQueue.hpp"
#include "Semaphore.hpp"

#define TIME_STAMP 1

BEGIN_TEST(blockingQ_fifo) 
    using namespace threads; 

    int removedItem = 0;
    BlockingQueue<int> bq(1000);
    for(int i = 0; i < 1000; ++i) {
        bq.Enqueue(i);    
    }
    bq.Dequeue(removedItem);
    ASSERT_EQUAL(removedItem, 0);    
END_TEST


threads::BlockingQueue<int> bq(1000);

void EnQ(int arg) {
    for(;;) {        
        bq.Enqueue(1);         
        std:: cout << "thread no. " << arg << " : added: " << 1 << std::endl; 
        std:: cout << "SIZE E:  " << bq.Size() << std::endl;           
    }  
}

void DeQ(int arg) {           
    int rmv;      
    for(;;) {  
        bq.Dequeue(rmv); 
        std:: cout << "thread no. :" << arg << " removed elem :" << rmv << '\n';  
        std:: cout << "SIZE D:  " << bq.Size() << std::endl;           
    }    
}

BEGIN_TEST(blockingQ_1K_capacity) 

    std::vector<std::thread> threads;
    
    threads.push_back(std::thread(EnQ, 1));
    threads.push_back(std::thread(EnQ, 1));
    threads.push_back(std::thread(EnQ, 1));
    threads.push_back(std::thread(DeQ, 1)); 
    threads.push_back(std::thread(DeQ, 2));    
     
    for(auto &e : threads) {
        e.join();
    }
    
    std::cout << "-----------------\n";
    std::cout << "SIZE: " << bq.Size() << '\n';
    
    ASSERT_PASS();
END_TEST

threads::BlockingQueue<int> queue(1000);

void EnqueueInt(int a_num) {    

    for(int i = a_num; i < a_num + 500; ++i) {
        queue.Enqueue(i);
    }    
}

std::vector<int> zeroTo500;
std::vector<int> above500;

void DequeueInt() {

    int toRemove;

    for(int i = 0; i < 1000; ++i) {
        queue.Dequeue(toRemove);
        if(toRemove < 500) {
            zeroTo500.push_back(toRemove);
        }
        else {
            above500.push_back(toRemove);
        }
    }
}

BEGIN_TEST(check_fifo_oneThread_DeQ) 
    
    std::thread t1(EnqueueInt, 0);
    std::thread t2(EnqueueInt, 500);  
      
    std::thread t3(DequeueInt);
    
    t1.join();
    t2.join();
    t3.join(); 

    std::vector<int>::const_iterator it1 = zeroTo500.begin();
    std::vector<int>::const_iterator it2 = above500.begin();

    while(it1++ != zeroTo500.end() - 1) {
        ASSERT_THAT(*it1 < *it1 + 1);
    }
    while(it2++ != above500.end() - 1) {
        ASSERT_THAT(*it2 < *it2 + 1);
    }
    
END_TEST

threads::BlockingQueue<int> queue2(1000);

std::vector<int> zeroTo500ForThread1;
std::vector<int> zeroTo500ForThread2;
std::vector<int> above500ForThread1;
std::vector<int> above500ForThread2;

void EnqueueInt2(int a_num) {     
    for(int i = a_num; i < a_num + 500; ++i) {    
        queue2.Enqueue(i);
    }    
}

void DequeueInt2(std::vector<int>& a_under500, std::vector<int>& a_above500) {    
    int toRemove;

    for(int i = 0; i < 500; ++i) {
        queue2.Dequeue(toRemove);
        if(toRemove < 500) {
            a_under500.push_back(toRemove);
        }
        else {
            a_above500.push_back(toRemove);
        }    
    }
}

void checkVecOrder(const std::vector<int>& a_vec) {    

    for(size_t i = 0; i < a_vec.size() - 1; ++i) {
        if(!a_vec.size()) { //since it's size_t, if vec is empty, (size - 1) is a large number, thus will lead to segfault
            break;
        }
        assert(a_vec[i] < a_vec[i + 1]);
    }
}

BEGIN_TEST(check_fifo_2Threads_DeQ_seperately) 
    
    std::thread t1(EnqueueInt2, 0);
    std::thread t2(EnqueueInt2, 500);  
      
    std::thread t3(DequeueInt2, std::ref(zeroTo500ForThread1), std::ref(above500ForThread1));
    std::thread t4(DequeueInt2, std::ref(zeroTo500ForThread2), std::ref(above500ForThread2));       
     
    t1.join();
    t2.join();
    t3.join();
    t4.join();  

    checkVecOrder(zeroTo500ForThread1); 
    checkVecOrder(zeroTo500ForThread2);
    checkVecOrder(above500ForThread1);
    checkVecOrder(above500ForThread2); 

    ASSERT_PASS();
    
END_TEST

BEGIN_TEST(check_fifo_2Threads_DeQ_together) 
    
    std::thread t1(EnqueueInt2, 0);
    std::thread t2(EnqueueInt2, 500);  
      
    std::thread t3(DequeueInt2, std::ref(zeroTo500ForThread1), std::ref(above500ForThread1));
    std::thread t4(DequeueInt2, std::ref(zeroTo500ForThread2), std::ref(above500ForThread2)); 
      
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    checkVecOrder(zeroTo500ForThread1); 
    checkVecOrder(zeroTo500ForThread2);
    checkVecOrder(above500ForThread1);
    checkVecOrder(above500ForThread2);     
    
    std::vector<int>::const_iterator it1 = zeroTo500ForThread1.begin();
    std::vector<int>::const_iterator it2 = zeroTo500ForThread2.begin();
    //TODO: export to a function
    if(zeroTo500ForThread1[0] == 0) { 
        if(zeroTo500ForThread2.empty()) {
            ASSERT_PASS();
        } 
        else {    
            while(it1 < zeroTo500ForThread1.end()) {
                while((*it1) + 1 == *(it1 + 1)) {
                    ++it1;
                }                
                ASSERT_THAT(*it2 == (*it1) + 1);  
                ++it1;
                if(it1 >= zeroTo500ForThread1.end()) {
                    break;
                }
                while((*it2) + 1 == *(it2 + 1)) {
                    ++it2;
                }
                ASSERT_THAT(*it1 == (*it2) + 1); 
                ++it2;
                if(it2 >= zeroTo500ForThread2.end()) {
                    break;
                }
            }
        }
    }
    if(zeroTo500ForThread2[0] == 0) {  
        if(zeroTo500ForThread1.empty()) {
            ASSERT_PASS();
        } 
        else {      
            while(it2 < zeroTo500ForThread2.end()) {
                while((*it2) + 1 == *(it2 + 1)) {
                    ++it2;
                }                
                ASSERT_THAT(*it1 == (*it2) + 1);  
                ++it2;
                if(it2 >= zeroTo500ForThread2.end()) {
                    break;
                }
                while((*it1) + 1 == *(it1 + 1)) {
                    ++it1;
                }
                ASSERT_THAT(*it2 == (*it1) + 1); 
                ++it1;
                if(it1 >= zeroTo500ForThread1.end()) {
                    break;
                }
            }
        }
    }
    ASSERT_PASS();
    
END_TEST


struct Ball {

    Ball(int a_value) : m_value(a_value) {}
    Ball() = default;

    int m_value;
    mutable std::chrono::time_point<std::chrono::steady_clock> m_ingress;
    std::chrono::time_point<std::chrono::steady_clock> m_egress;
};

threads::BlockingQueue<Ball> ballsQueue(1000);

std::vector<Ball> under500ForThread1;
std::vector<Ball> under500ForThread2;
std::vector<Ball> over500ForThread1;
std::vector<Ball> over500ForThread2;

void EnqueueBalls(int a_num) {  
    
    for(int i = a_num; i < a_num + 500; ++i) {        
        Ball b(i);
        ballsQueue.Enqueue(b);
    }    
}

void DequeueBalls(std::vector<int>& a_under500, std::vector<int>& a_above500) {
    
    Ball toRemove;

    for(int i = 0; i < 500; ++i) {        
        ballsQueue.Dequeue(toRemove);
        if(toRemove.m_value < 500) {
            a_under500.push_back(toRemove.m_value);
        }
        else {
            a_above500.push_back(toRemove.m_value);
        }           
    }
}

bool checkSyncWithClock(const std::vector<Ball>& a_first, const std::vector<Ball>& a_second,
std::chrono::time_point<std::chrono::steady_clock> a_startTime, int a_from) {

    std::chrono::time_point<std::chrono::steady_clock> ingress = a_startTime;
    std::chrono::time_point<std::chrono::steady_clock> egress = a_startTime;

    for(int i = a_from; i < a_from + 500; ++i) {
        if(a_first[i].m_ingress > ingress && a_first[i].m_egress > egress) {
            ingress = a_first[i].m_ingress;
            egress = a_first[i].m_egress;
        }
        else if(a_second[i].m_ingress > ingress && a_second[i].m_egress > egress) {
            ingress = a_second[i].m_ingress;
            egress = a_second[i].m_egress;
        }
        else {
            return false;   
        }
    }
    return true;
}

BEGIN_TEST(check_fifo_2Threads_DeQ_ballsQ) 
    
    std::thread t1(EnqueueBalls, 0);
    std::thread t2(EnqueueBalls, 500);  
      
    std::thread t3(DequeueBalls, std::ref(under500ForThread1), std::ref(over500ForThread1));
    std::thread t4(DequeueBalls, std::ref(under500ForThread2), std::ref(over500ForThread2)); 
      
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    checkVecOrder(zeroTo500ForThread1); 
    checkVecOrder(zeroTo500ForThread2);
    checkVecOrder(above500ForThread1);
    checkVecOrder(above500ForThread2); 

    auto startTime = std::chrono::steady_clock::now(); 

    ASSERT_THAT(checkSyncWithClock(under500ForThread1, over500ForThread1, startTime, 0));
    ASSERT_THAT(checkSyncWithClock(under500ForThread2, over500ForThread2, startTime, 500));        
    
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
		
    // TEST(blockingQ_fifo) 
    // TEST(blockingQ_1K_capacity)         		
    // TEST(check_fifo_oneThread_DeQ)
    // TEST(check_fifo_2Threads_DeQ_seperately)
    // TEST(check_fifo_2Threads_DeQ_together)
    TEST(check_fifo_2Threads_DeQ_ballsQ)

END_SUITE





















