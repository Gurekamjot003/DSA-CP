#include <iostream>
using namespace std;

class unary
{
    int a;
    int b;

public:
    void setdata(int x, int y)
    {
        a = x;
        b = y;
    }
    void getdata()
    {
        cout << a << endl
             << b << endl
             << endl;
    }
    friend void operator-(unary &);
};

void operator-(unary &obj)
{
    obj.a = -obj.a;
    obj.b = -obj.b;
}

int main()
{
    unary o1;
    o1.setdata(-10, 20);
    o1.getdata();
    -o1;
    o1.getdata();
    return 0;
}