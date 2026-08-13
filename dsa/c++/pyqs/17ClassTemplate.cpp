// Syntax of class templates

#include <iostream>
using namespace std;

template <class T>
class Add
{
public:
    Add(T a, T b)
    {
        cout << a + b << endl;
    }
};

int main()
{
    Add<float> a(1.5, 2.5);
    return 0;
}