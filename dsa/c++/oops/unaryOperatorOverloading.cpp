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
    void operator-()
    {
        a = -a;
        b = -b;
    }
};

int main()
{
    unary o1;
    o1.setdata(-10, 20);
    o1.getdata();
    -o1;
    o1.getdata();
    return 0;
}