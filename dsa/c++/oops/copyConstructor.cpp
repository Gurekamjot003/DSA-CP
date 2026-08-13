#include <iostream>
using namespace std;

class Yugam
{
    int x;
    int y;

public:
    Yugam(int x1, int y1)
    {
        x = x1;
        y = y1;
    };
    void getData()
    {
        cout << x << endl
             << y << endl
             << endl;
    }
    Yugam(Yugam &y10)
    {
        x = y10.x;
        y = y10.y;
    }
};

int main()
{
    Yugam y1(5, 10), y2 = y1;
    y1.getData();
    y2.getData();
    return 0;
}