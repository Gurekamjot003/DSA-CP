// wap to print size in bytes of different data types

#include <iostream>
using namespace std;

class size
{
    int a;
    char b;
    float c;
    double d;

public:
    void display()
    {
        cout << "Size of int data type is: " << sizeof(a)<<" bytes. " << endl;
        cout << "Size of char data type is: " << sizeof(b)<<" bytes. " << endl;
        cout << "Size of float data type is: " << sizeof(c)<<" bytes. " << endl;
        cout << "Size of double data type is: " << sizeof(d)<<" bytes. " << endl;
    }
};

int main()
{
    size s;
    s.display();
    return 0;
}