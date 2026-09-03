#include<stdio.h>

void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int*nums, int n){
    for(int gap = n/2; gap>=1; gap/=2){
        for(int i = gap; i<n; i++){
            for(int j = i-gap; j>=0; j-=gap){
                if(nums[j]>nums[j+gap]) swap(&nums[j], &nums[j+gap]);
                else break;
            }
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