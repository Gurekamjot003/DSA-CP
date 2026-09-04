#include <stdio.h>

void swap(double *a, double *b)
{
    double c = *a;
    *a = *b;
    *b = c;
}

void insertion_sort(double *nums, int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] > nums[j + 1])
                swap(&nums[j], &nums[j + 1]);
            else
                break;
        }
    }
}

void sort(double *nums, int n)
{
    int bucket_count = 10; // total buckets

    double max_val = -(1 << 30);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > max_val)
            max_val = nums[i];
    }
    double gap = (max_val + 1) / bucket_count;
    int size[bucket_count];
    for (int i = 0; i < bucket_count; i++)
        size[i] = 0;
    double buckets[bucket_count][n];

    for (int i = 0; i < n; i++)
    {
        int cur_bucket = nums[i] / gap;
        buckets[cur_bucket][size[cur_bucket]++] = nums[i];
    }

    for (int i = 0; i < bucket_count; i++)
    {
        insertion_sort(buckets[i], size[i]);
    }

    int ptr = 0;
    for (int i = 0; i < bucket_count; i++)
    {
        for (int j = 0; j < size[i]; j++)
        {
            nums[ptr++] = buckets[i][j];
        }
    }
}

int main()
{
    double arr[] = {10, 20, 54, 21, 2, 101}; // should have values bw 0 and 1
    int n = 6;

    sort(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");
    return 0;
}