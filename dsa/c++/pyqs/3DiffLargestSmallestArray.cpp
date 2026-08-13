// wap that prints the difference bw smallest and the largest element in an array

#include <iostream>
using namespace std;

class arraydiff
{
    int arr[10];
    int smallest;
    int largest;
    int difference;

public:
    void setData()
    {
        cout << "Enter 10 elements in the array: " << endl;
        for (int i = 0; i < 10; i++)
        {
            cin >> arr[i];
        }
    }
    void getDiff()
    {
        int smallest = INT8_MAX;
        int largest = INT8_MIN;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] < smallest)
            {
                smallest = arr[i];
            }
            if (arr[i] > largest)
            {
                largest = arr[i];
            }
        }
        difference = largest - smallest;
        cout << difference;
    }
};

int main()
{
    arraydiff a1;
    a1.setData();
    a1.getDiff();
    return 0;
}