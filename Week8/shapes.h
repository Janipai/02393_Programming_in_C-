#ifndef __shapes__
#define __shapes__

class Shape
{
private:
    /* data */
public:
    virtual double area(void) = 0;
    virtual double perimeter(void) = 0;
    virtual double height(void) = 0;
    virtual double width(void) = 0;
    virtual void rotate(void) = 0;
};

class Rectangle : public Shape
{
public:
    double h;
    double w;

    Rectangle(double h, double w);
    ~Rectangle();
    virtual double area(void);
    virtual double perimeter(void);
    virtual double height(void);
    virtual double width(void);
    virtual void rotate(void);
};

class Square : public Rectangle
{
public:
    double length;

    Square(double length);
    ~Square();
    void rotate(void);
};

class Circle : public Shape
{
private:
    double r;

public:
    Circle(double r);
    ~Circle();
    double area(void);
    double perimeter(void);
    double height(void);
    double width(void);
    void rotate(void);
};
#endif