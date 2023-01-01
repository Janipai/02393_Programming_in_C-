#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods
LimitedBuffer::LimitedBuffer(unsigned int maxBufCap, int defaultValue){
    this->maxBufCap = maxBufCap;
    this->defaultValue = defaultValue;
    bufferCounter = 0;
}

// Task 4(b).  Write a working implementation of write() and occupancy()
void LimitedBuffer::write(int v){
    if (bufferCounter == maxBufCap)
        return;
    data.push_back(v);
    bufferCounter++;
}
unsigned int LimitedBuffer::occupancy(){
    return bufferCounter;
}
// Task 4(c).  Write a working implementation of read()
int LimitedBuffer::read(){
    if (data.empty())
        return defaultValue;
    bufferCounter--;
    int removedValue = data[0];
    data.erase(data.begin());
    return removedValue;
      
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
