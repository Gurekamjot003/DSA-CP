#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 2; i < n; i++)
    {
        int flag = 0;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << i << endl;
            sum += i;
        }
    }
    cout << sum;
    return 0;
}
