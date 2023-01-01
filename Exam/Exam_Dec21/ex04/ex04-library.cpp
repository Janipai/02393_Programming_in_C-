#include "ex04-library.h"
#include <cmath>

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods
SensorBuffer::SensorBuffer(unsigned int avgNumber)
{
    this->avgNumber = avgNumber;
    this->counter = 0;
}

// Task 4(b).  Write a working implementation of write() and writeCount()

void SensorBuffer::write(int v)
{
    this->data.push_back(v);
    this->counter++;

    if (this->avgNumber < this->counter)
        data.erase(data.begin());
}
unsigned int SensorBuffer::writeCount() { return this->counter; }

// Task 4(c).  Write a working implementation of read()
int SensorBuffer::read()
{
    if (data.empty())
        return 0;
    else
        return data.back();
}

// Task 4(d).  Write a working implementation of readAvg()
int SensorBuffer::readAvg()
{
    if (data.empty())
        return 0;

    unsigned int nvalues = this->counter < this->avgNumber ? this->counter : this->avgNumber;
    int avg = 0;

    for (unsigned int i = 0; i < nvalues; i++)
    {
        avg += this->data[i];
    }
    return avg / nvalues;
}

// Do not modify
Buffer::~Buffer()
{
    // Empty destructor
}
