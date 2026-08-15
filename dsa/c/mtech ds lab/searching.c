#include <stdio.h>

void swap(int *a1, int *a2)
{
    int c = *a1;
    *a1 = *a2;
    *a2 = c;
}

int main()
{
    int arr[] = {1, 2, 3, 2, 4, 1, 4, 5};
    int sz = sizeof(arr) / sizeof(int);
    int target = 4;
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == target)
        {
            printf("found using linear search\n");
            break;
        }
    }

    for (int i = 0; i < sz; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (arr[j] < arr[i])
                swap(&arr[j], &arr[i]);
        }
    }

    int left = 0, right = sz - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == target)
        {
            printf("Found using binary search\n");
            break;
        }
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}