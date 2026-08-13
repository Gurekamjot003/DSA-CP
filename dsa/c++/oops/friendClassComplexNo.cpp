#include <iostream>
using namespace std;

class Complex
{
    int a;
    int b;

public:
    void setNumber(int x, int y)
    {
        a = x;
        b = y;
    }
    void printNumber()
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
    friend class calculator;
};

class calculator
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }
    Complex sumComplexReal(Complex c11, Complex c12)
    {
        Complex c13;
        c13.a = c11.a + c12.a;
        return c13;
    }
    Complex sumComplexImg(Complex c11, Complex c12)
    {
        Complex c13;
        c13.b = c11.b + c12.b;
        return c13;
    }
};

int main()
{
    Complex c1, c2, c3;
    c1.setNumber(1, 2);
    c1.printNumber();
    c2.setNumber(3, 4);
    c2.printNumber();
    calculator cal1;

    c3 = cal1.sumComplexReal(c1, c2);
    c3 = cal1.sumComplexImg(c1, c2);
    c3.printNumber();
    return 0;
}