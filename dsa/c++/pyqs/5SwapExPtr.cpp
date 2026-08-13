#include <iostream>
using namespace std;

class swapp
{
public:
    
    swapp(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

int main()
{
    int a = 4, b = 5;
    cout << a << " " << b << endl;
    swapp(&a, &b);
    cout << a << " " << b << endl;
    return 0;
}