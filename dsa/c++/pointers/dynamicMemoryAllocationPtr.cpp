#include <iostream>
using namespace std;

int main()
{
    int *b = new int(5);
    cout << *b << endl;

    int *arr = new int[3];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    cout << "Value at address 0 is: " << arr[0] << endl;
    cout << "Value at address 1 is: " << arr[1] << endl;
    cout << "Value at address 2 is: " << arr[2] << endl;

    return 0;
}