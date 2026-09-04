#include<stdio.h>

void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void merge(int* nums, int l, int mid, int r){
    int arr[r-l+1];
    int ptr1 = l, ptr2 = mid+1, ptr = 0;
    while(ptr1<=mid && ptr2<=r){
        if(nums[ptr1]<nums[ptr2]){
            arr[ptr++] = nums[ptr1++];
        }
        else{
            arr[ptr++] = nums[ptr2++];
        }
    }
    while (ptr1<=mid)
    {
        arr[ptr++] = nums[ptr1++];
    }
    while (ptr2<=r)
    {
        arr[ptr++] = nums[ptr2++];
    }
    for(int i = 0; i<(r-l+1); i++){
        nums[i+l] = arr[i];
    }
}

void merge_sort(int* nums, int l, int r){
    if(r-l < 1) return;
    int mid = (l+r)/2;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid+1, r);
    merge(nums, l, mid, r);
}

void sort(int*nums, int n){
    merge_sort(nums, 0, n-1);
}

int main(){
    int arr[] = {10, 20, 54, 21, 2, 101};
    int n = 6;
    
    sort(arr, n);
    printf("\n");
    for(int i = 0; i<n;  i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}