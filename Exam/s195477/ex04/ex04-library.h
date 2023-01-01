#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_
#include <map>
#include <vector>

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual void clear() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class CountingBuffer, by extending Buffer
// Write your code here
class CountingBuffer :public Buffer
{
private:
    int defaultValue;
    std::map<int, int> mp;
public:
    CountingBuffer(int defaultValue);
    void write(int v);
    void clear();
    unsigned int frequency(int v);
    int mostFrequent();
};

#endif /* EX04_LIBRARY_H_ */
