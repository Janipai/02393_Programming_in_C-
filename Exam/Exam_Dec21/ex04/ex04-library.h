#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_
#include <vector>

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here
class SensorBuffer: public Buffer
{
private:
    std::vector<int> data;
    unsigned int counter, avgNumber;
public:
    SensorBuffer(unsigned int avgNumber);

    void write(int v);
    int read();
    int readAvg();
    unsigned int writeCount();
};

#endif /* EX04_LIBRARY_H_ */