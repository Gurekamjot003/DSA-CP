#include <iostream>
using namespace std;

int main()
{
    int a = 10, b = 0, c;
    try
    {
        if (b == 0)
        {
            throw 10;
        }
        else
        {
            c = a / b;
            cout << c;
        }
    }
    catch (int ex)
    {
        cout << "Division by zero";
    }
    return 0;
}