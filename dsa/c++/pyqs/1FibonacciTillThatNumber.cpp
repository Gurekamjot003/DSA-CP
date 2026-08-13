// wap that asks user to enter a number and displays the fibonacci series till that number

#include <iostream>
using namespace std;

class fibo
{
    int a;
    int b;
    int c;

public:
    void setNumbers()
    {
        a = 0;
        b = 1;
        c = a + b;
    }
    void getNumbers(int n)
    {
        while (a < n)
        {
            cout << a << endl;
            a = b;
            b = c;
            c = a + b;
        }
    }
};

int main()
{
    fibo f;
    f.setNumbers();
    int n;
    cout << "Enter the value: ";
    cin >> n;
    f.getNumbers(n);
    return 0;
}