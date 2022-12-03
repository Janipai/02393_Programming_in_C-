#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_
#include <vector>

class Buffer
{
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here

class SensorBuffer : public Buffer
{
private:
    int defaultValue;
    int minValue;
    int maxValue;
    std::vector<int> storedValues;
    int outOfRangeCounter;

public:
    SensorBuffer(int defaultValue, int minValue, int maxValue);
    ~SensorBuffer();

    virtual void write(int v);
    virtual int read();

    unsigned int faults();
    void clear();
};

#endif /* EX04_LIBRARY_H_ */
