#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 100, 200};
    int *ptr;
    for (int i = 0; i < 3; i++)
    {
        ptr = &arr[i];
        cout << arr[i]<<endl;
        cout << ptr<<endl;
    }
    return 0;
}