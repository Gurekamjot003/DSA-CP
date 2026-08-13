// wap to create a class box with fields width, height and depth. Initialize data members using default, parameterized and copy constructor and calculate the volume of the box

#include <iostream>
using namespace std;

class Box
{
    int width;
    int height;
    int depth;
    int volume;

public:
    void getVolume()
    {
        volume = width * depth * height;
        cout << volume << endl;
    }

    // default constructor
    Box()
    {
        width = height = depth = 5;
    }

    // parameterized constructor
    Box(int a, int b, int c)
    {
        width = a;
        height = b;
        depth = c;
    }

    // copy constructor
    Box(Box &b)
    {
        width = b.width;
        height = b.height;
        depth = b.depth;
    }
};

int main()
{
    Box b1;
    b1.getVolume();
    Box b2(1, 2, 5);
    b2.getVolume();
    Box b3(b2);
    b3.getVolume();
    return 0;
}