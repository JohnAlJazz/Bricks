#include <thread>
#include <unistd.h>

#include "mu_test.h"
#include "BlockingQueue.hpp"
#include "Semaphore.hpp"

BEGIN_TEST(blockingQ_fifo) 
    using namespace threads; 

    BlockingQueue<int> bq(1000);
    for(int i = 0; i < 1000; ++i) {
        bq.Enqueue(i);    
    }
    int element = bq.Dequeue();
    ASSERT_EQUAL(element, 0);    
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
    int rmv = 0;      
    for(;;) {  
        rmv = bq.Dequeue(); 
        std:: cout << "thread no. :" << arg << " removed elem :" << rmv << '\n';  
        std:: cout << "SIZE D:  " << bq.Size() << std::endl;           
    }    
}

BEGIN_TEST(blockingQ_1K_capacity) 
    
    std::thread t1(EnQ, 1);
    std::thread t3(EnQ, 1);
    std::thread t4(EnQ, 1);
    std::thread t5(DeQ, 1); 
    std::thread t2(DeQ, 2);    
     
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    
    std::cout << "-----------------\n";
    std::cout << "SIZE: " << bq.Size() << '\n';
    
    ASSERT_PASS();
END_TEST


class Cat{};
Cat c;

threads::BlockingQueue<Cat> catsQ;

void CatsEnQ() {

    for(;;) {
        catsQ.Enqueue(c);
        std::cout << "SIZE: " << catsQ.Size() << '\n';
    }
}

void CatsDeQ() {

    Cat c2;
    for(;;) {
        c2 = catsQ.Dequeue();
        std::cout << "SIZE: " << catsQ.Size() << '\n';
    }
}

BEGIN_TEST(blockingQ_infinte_cats) 
    
    std::thread t1(CatsEnQ);
    std::thread t2(CatsDeQ);

    t1.join();
    t2.join();
    
    ASSERT_PASS();
END_TEST

BEGIN_SUITE(Its what you learn after you know it all that counts)
		
    // TEST(blockingQ_fifo) 
    // TEST(blockingQ_1K_capacity)
    // TEST(blockingQ_infinte_cats)      		

END_SUITE