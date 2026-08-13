// programming example to illustrate inline function

#include <iostream>
using namespace std;

class A
{
    int x;

public:
    inline void setData(int a)
    {
        x = a;
    }
    friend void getData(A);
};

void getData(A a)
{
    cout << a.x;
}

int main()
{
    A a;
    a.setData(5);
    getData(a);

    return 0;
}