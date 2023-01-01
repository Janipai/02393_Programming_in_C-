#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of CountingBuffer's
//             constructor and methods
CountingBuffer::CountingBuffer(int defaultValue){
    this->defaultValue = defaultValue;
}
// Task 4(b).  Write a working implementation of write() and frequency()
void CountingBuffer::write(int v){
    if (mp.empty())
        mp.insert({v,1});
    else{
        for (auto x: mp){
            if (x.first == v){
                x.second = x.second++;
                return;
            }
            
        }
        mp.insert({v,1});
    }
    
}
unsigned int CountingBuffer::frequency(int v){
    if (mp.empty())
        return 0;
    
    for (auto x: mp){
        if (x.first == v)
            return x.second;            
    }
}

// Task 4(c).  Write a working implementation of mostFrequent()
int CountingBuffer::mostFrequent(){
    int theValue = 0;
    int hyppist = 0;
    if (mp.empty())
        return defaultValue;
    else{
        for (auto x = mp.rbegin(); x != mp.rend(); x++) {
            if (x->second >= hyppist){
                theValue = x->first;
                hyppist = x->second;
            }  
        }
        return theValue;
    }
}

// Task 4(d).  Write a working implementation of clear()
void CountingBuffer::clear(){
    mp.clear();
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
