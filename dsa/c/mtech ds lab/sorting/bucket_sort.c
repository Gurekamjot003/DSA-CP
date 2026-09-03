#include<stdio.h>

void swap(int* a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void sort(int*nums, int n){
    int bucket_count = 10; // total buckets 

    double gap = 1.0/bucket_count;
    

}

int main(){
    int arr[] = {10, 20, 54, 21, 2, 101}; // should have values bw 0 and 1
    int n = 6;
    
    sort(arr, n);
    printf("\n");
    for(int i = 0; i<n;  i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}