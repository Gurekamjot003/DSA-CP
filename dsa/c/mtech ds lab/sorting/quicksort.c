#include<stdio.h>

void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

int partition(int*nums, int l, int r){
    int pivot = r--;
    while(l<r){

        while(l<r && nums[l]<= nums[pivot]) l++;
        while(l<r && nums[r]>= nums[pivot]) r--;
        if(l<r) swap(&nums[l], &nums[r]);
    }
    if(nums[l] > nums[pivot]){
        swap(&nums[l], &nums[pivot]);
        return l;
    }
    if(nums[r] > nums[pivot]){
        swap(&nums[r], &nums[pivot]);
        return r;
    }
    return pivot;

}

void quick_sort(int* nums, int l, int r){
    if(r-l+1 <= 1) return;
    int mid = partition(nums, l, r);
    quick_sort(nums, l, mid-1);
    quick_sort(nums, mid+1, r);
}

void sort(int*nums, int n){
    quick_sort(nums, 0, n-1);
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