#include <iostream>
#include <string>
using namespace std;

class fraction
{
private:
    // Internal representation of a fraction as two integers
    int numerator;
    int denominator;

public:
    // Class constructor
    fraction(int n, int d);

    // Methods to update the fraction
    void add(fraction f);
    void mult(fraction f);
    void div(fraction f);

    // Display method
    void simplify(void);

    // Display method
    void display(void);
};

fraction::fraction(int n, int d)
{
    numerator = n;
    denominator = d;
}
void fraction::add(fraction f)
{
    numerator = (numerator * f.denominator) + (f.numerator * denominator);
    denominator = (denominator * f.denominator);
}

void fraction::mult(fraction f)
{
    numerator = numerator * f.numerator;
    denominator = denominator * f.denominator;
}
void fraction::div(fraction f)
{
    numerator = numerator * f.denominator;
    denominator = denominator * f.numerator;
}

void fraction::simplify()
{
    int a = numerator;
    int b = denominator;
    int t;

    while (b!=0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    
    numerator = numerator / a;
    denominator = denominator / a;
}

void fraction::display()
{
    cout << numerator << " / " << denominator << endl;
}

void calculate(string op, fraction f1, fraction f2)
{
    if (op == "+")
        f1.add(f2);
    else if (op == "*")
        f1.mult(f2);
    else if (op == "div")
        f1.div(f2);
    else
        exit(0);

    f1.simplify();
    f1.display();
}

int main()
{
    int a, b, c, d;
    string operation, slash;

    cin >> a;
    while (!cin.fail())
    {
        cin >> slash;
        cin >> b;

        fraction fraction1(a, b);

        cin >> operation;
        cin >> c;
        cin >> slash;
        cin >> d;

        fraction fraction2(c, d);

        calculate(operation, fraction1, fraction2);
        cin >> a;
    }
}