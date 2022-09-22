#include <iostream>
#include <assert.h>

#include "Threads.hpp"
#include "Mutex.hpp"
#include "ThreadsErrors.hpp"

int gCounter = 0;

void* Incrementer(void* a_arg) {  

    ++*static_cast<int*>(a_arg);
    return NULL;
}

void incrementTest() {
    using namespace threads;  

    Thread t1(Incrementer, &gCounter);
    Thread t2(Incrementer, &gCounter);

    t1.Join();
    t2.Join(); 

    assert(gCounter == 2);
    std::cout << "increment PASS\n"; 
    gCounter = 0;   
}

void* Decrementer(void* a_arg) {
    --*static_cast<int*>(a_arg);
    return NULL;
}

void decrementTest() {
    using namespace threads;  

    Thread t1(Decrementer, &gCounter);
    Thread t2(Decrementer, &gCounter);

    t1.Join();
    t2.Join(); 

    assert(gCounter == -2);
    std::cout << "decrement PASS\n";  
    gCounter = 0;  
}

void* Incrementer1K(void* a_arg) { 

    for(int i = 0; i < 1000; ++i) { 
        ++*static_cast<int*>(a_arg); 
        
        std::cout << *static_cast<int*>(a_arg) << '\n';       
    }
    return NULL;
}

void* Decrementer1K(void* a_arg) { 

    for(int i = 0; i < 1000; ++i) { 
        --*static_cast<int*>(a_arg); 

        std::cout << *static_cast<int*>(a_arg) << '\n';       
    }
    return NULL;
}


void noSync1K() {
    using namespace threads;  

    Thread t1(Incrementer1K, &gCounter);
    Thread t2(Decrementer1K, &gCounter);

    t1.Join();
    t2.Join(); 

    gCounter = 0;   
}



void* Incrementer50M(void* a_arg) { 

    for(size_t i = 0; i < 50'000'000; ++i) { 
        ++*static_cast<int*>(a_arg);        
    }
    return NULL;
}

void* Decrementer50M(void* a_arg) { 

    for(size_t i = 0; i < 50'000'000; ++i) { 
        --*static_cast<int*>(a_arg);        
    }
    return NULL;
}


void noSync50M() {
    using namespace threads;  

    Thread t1(Incrementer50M, &gCounter);
    Thread t2(Decrementer50M, &gCounter);

    t1.Join();
    t2.Join();    
    assert(gCounter != 0);
    std::cout << "5M PASS\n";
}

threads::Mutex mutex;

void* SyncIncrementer50M(void* a_arg) { 

    for(size_t i = 0; i < 50'000'000; ++i) { 
        mutex.Lock();
        ++*static_cast<int*>(a_arg);
        mutex.Unlock();        
    }
    return NULL;
}

void* SyncDecrementer50M(void* a_arg) { 

    for(size_t i = 0; i < 50'000'000; ++i) { 
        mutex.Lock();
        --*static_cast<int*>(a_arg);
        mutex.Unlock();        
    }
    return NULL;
}

void Sync50M() {
    using namespace threads;
    gCounter = 0;  

    Thread t1(SyncIncrementer50M, &gCounter);
    Thread t2(SyncDecrementer50M, &gCounter);

    t1.Join();
    t2.Join();    

    assert(gCounter == 0);
    std::cout << "5M sync PASS\n";
}

int main() {
    
    incrementTest();
    std::cout << "\n\n";

    decrementTest();
    std::cout << "\n\n";
    
    noSync1K();
    std::cout << "\n\n";

    for(int i = 0; i < 50; ++i) {
        noSync50M();
        std::cout << "gCounter: " << gCounter << '\n';
    }
    std::cout << "\n\n";

    for(int i = 0; i < 10; ++i) {
        Sync50M();
        std::cout << "gCounter: " << gCounter << '\n';
    }   
    
}

