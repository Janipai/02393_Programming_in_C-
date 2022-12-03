#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods
SensorBuffer::SensorBuffer(int defaultValue, int minValue, int maxValue)
{
    this->defaultValue = defaultValue;
    this->minValue = minValue;
    this->maxValue = maxValue;
    this->outOfRangeCounter = 0;
}
void SensorBuffer::write(int v)
{
    if (v > this->minValue && v < this->maxValue)
    {
        this->storedValues.push_back(v);
    }
    else if (v < this->minValue)
    {
        this->storedValues.push_back(minValue);
        this->outOfRangeCounter++;
    }
    else if (v > this->maxValue)
    {
        this->storedValues.push_back(maxValue);
        this->outOfRangeCounter++;
    }
}
int SensorBuffer::read() {
    if (this->storedValues.empty())
    {
        return this->defaultValue;
    }else{
        int oldestElement = this->storedValues.front();
    this->storedValues.erase(this->storedValues.begin());
    return oldestElement;
    }    
}
unsigned int SensorBuffer::faults() {
    return outOfRangeCounter;
}
void SensorBuffer::clear() {
    this->storedValues.clear();
    this->outOfRangeCounter = 0;
}

// Task 4(b).  Write a working implementation of write() and faults()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of clear()

// Do not modify
Buffer::~Buffer()
{
    // Empty destructor
}
