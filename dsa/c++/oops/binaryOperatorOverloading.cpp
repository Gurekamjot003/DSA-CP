#include <iostream>
using namespace std;

class binary
{
    int a;
    int b;

public:
    void setData(int x, int y)
    {
        a = x;
        b = y;
    }
    void getData()
    {
        cout << a << endl
             << b << endl
             << endl;
    }
    binary operator+(binary &obj)
    {
        binary temp;
        temp.setData(0, 0);
        temp.a = a + obj.a;
        temp.b = b + obj.b;
        return temp;
    }
};

int main()
{
    binary b1, b2, b3;
    b1.setData(1, 2);
    b1.getData();
    b2.setData(3, 4);
    b2.getData();
    b3 = b1 + b2;
    b3.getData();
    return 0;
}