//[1,6,3,7]=[1],[6],[3],[7],[1,6],[6,3],[3,7],[1,6,3],[6,3,7],[1,6,3,7]

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
    {
        int index = 0;
        for (int j = n; j >= i; j--)
        {
            int A[i];
            for (int k = 0; k < i; k++)
            {
                A[k] = arr[k + index];
                cout << A[k] << " ";
            }
            index++;
            cout << '\n';
        }
    }
    return 0;
}