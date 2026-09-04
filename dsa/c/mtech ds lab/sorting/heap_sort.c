#include<stdio.h>

void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void heapify(int* nums, int i, int n){
    int max = nums[i];
    while(i<n){
        int left = i*2 + 1, right = i*2 + 2;
        int max_idx = i;
        if(left<n && nums[left]>nums[max_idx]) max_idx = left;
        if(right<n && nums[right]>nums[max_idx]) max_idx = right;
        if(max_idx == i) break;
        swap(&nums[i], &nums[max_idx]);
    }
}

void sort(int*nums, int n){
    for(int i = (n-2)/2; i>=0; i--){
        heapify(nums, i, n);
    }

    for(int r = n-1; r>0; r--){
        swap(&nums[0], &nums[r]);
        heapify(nums, 0, r);
    }
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