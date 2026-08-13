// wap to illustrate the concept of friend function

#include <iostream>
using namespace std;

class A
{
    int x;

public:
    void setData(int a)
    {
        x = a;
    }
    friend void display(A a);
};

void display(A a)
{
    cout << a.x;
}

int main()
{
    A a;
    a.setData(5);
    display(a);
    return 0;
}