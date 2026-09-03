#include<stdio.h>

void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int*nums, int n){
    for(int i = 0; i<n; i++){
        int min_val = nums[i];
        int idx = i;
        for(int j = i+1; j<n; j++){
            if(nums[j] < min_val){
                min_val = nums[j];
                idx = j;
            }
        }
        swap(&nums[i], &nums[idx]);
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