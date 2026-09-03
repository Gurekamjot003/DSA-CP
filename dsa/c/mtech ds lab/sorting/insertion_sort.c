#include<stdio.h>

void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int*nums, int n){
    for(int i = 1; i<n; i++){
        for(int j = i-1; j>=0; j--){
            if(nums[j] > nums[j+1]) swap(&nums[j], &nums[j+1]);
            else break;
        }
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