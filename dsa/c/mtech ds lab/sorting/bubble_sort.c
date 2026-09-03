#include<stdio.h>

void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int*nums, int n){
    for(int i = n-1; i>=0; i--){
        for(int j = 1; j<i; j++){
           
            if(nums[j-1] > nums[j]) swap(&nums[j], &nums[j-1]);
            
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