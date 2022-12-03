#include "shapes.h"
#include <math.h>

using namespace std;

Rectangle::Rectangle(double h, double w){
    this->h = h;
    this->w = w;
}
Rectangle::~Rectangle(){}

double Rectangle::area(){
    return (height() * width());
};

double Rectangle::perimeter(){
    return (2 * height()) + (2 * width());
};

double Rectangle::height(){
    return h;
};

double Rectangle::width(){
    return w;
};
void Rectangle::rotate(){
    double temp = h;
    h = w;
    w = temp;
};


Square::Square(double length) : Rectangle(length,length){
}
Square::~Square(){
}

void Square::rotate(){
    return;
};

Circle::Circle(double radius){
    r = radius;
}

Circle::~Circle(){}

double Circle::area(){
    return (3.14 * pow(r,2));
};

double Circle::perimeter(){
    return 2 * 3.14 * r;
};

double Circle::height(){
    return r*2;
};

double Circle::width(){
    return r*2;
};

void Circle::rotate(){};