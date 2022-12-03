#include "vector2d.h"
#include <cmath>
#include <vector>

using namespace std;

v2d::v2d(double a, double b)
{
    // Write your code here
    x = a;
    y = b;
}

v2d::v2d(const v2d &v)
{
    // Write your code here

    x = v.x;
    y = v.y;
}

v2d::~v2d()
{
    // Write your code here
}

v2d &v2d::operator=(const v2d &v)
{
    // Write your code here
    x = v.x;
    y = v.y;
    return *this;
}

v2d &v2d::operator+(const v2d &v)
{
    // Write your code here
    x += v.x;
    y += v.y;
    return *this;
}

double v2d::operator*(const v2d &v)
{
    // Write your code here
    return (x * v.x) + (y * v.y);
}

v2d &v2d::operator*(double k)
{
    // Write your code here
    x *= k;
    y *= k;
    return *this;
}

double v2d::length()
{
    // Write your code here

    return sqrt((*this) * (*this));
}
