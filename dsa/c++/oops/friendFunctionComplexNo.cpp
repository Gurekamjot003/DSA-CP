#include <iostream>
using namespace std;

class complex
{
    int a;
    int b;

public:
    friend complex sumComplex(complex c5, complex c6);
    void setNumber(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    void printNumber()
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }
};

complex sumComplex(complex c5, complex c6)
{
    complex c4;
    c4.a = c5.a + c6.a;
    c4.b = c5.b + c6.b;
    return c4;
}

int main()
{
    complex c1, c2, sum;
    c1.setNumber(1, 2);
    c1.printNumber();
    c2.setNumber(3, 4);
    c2.printNumber();
    sum = sumComplex(c1, c2);
    sum.printNumber();

    return 0;
}