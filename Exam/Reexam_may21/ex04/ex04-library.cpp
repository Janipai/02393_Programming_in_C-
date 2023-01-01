#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of FilteringBuffer's
//             constructor and methods
FilteringBuffer::FilteringBuffer(int defaultValue)
{
    this->defaultValue = defaultValue;
    this->occupancyCounter = 0;
}
// Task 4(b).  Write a working implementation of write() and occupancy()
    void FilteringBuffer::write(int v){

        if (find(this->data.begin(), this->data.end(), v) != this->data.end())
            return;
        else if (find(this->oldData.begin(), this->oldData.end(), v) != this->oldData.end()){
            this->data.push_back(v);
            occupancyCounter -= 2;
        }else{
            this->data.push_back(v);
            occupancyCounter++;
        }
    }
    unsigned int FilteringBuffer::occupancy(){
        return this->occupancyCounter;
    }

// Task 4(c).  Write a working implementation of read()
    int FilteringBuffer::read(){
        if (data.empty())
            return this->defaultValue;
        
        int oldestValue = this->data[0];
        oldData = data;

        data.erase(data.begin());
        occupancyCounter--;
        return oldestValue;
    }

// Task 4(d).  Write a working implementation of reset()
    void FilteringBuffer::reset(){
        data.clear();
        oldData.clear();
        occupancyCounter = 0;
    }

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}