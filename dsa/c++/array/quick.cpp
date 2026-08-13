#include<iostream>
using namespace std;

void quick(int arr[], int size){
    int left_ptr=0, right_ptr=size-1, loc=0;
    while(left_ptr<right_ptr){
        while(loc<right_ptr){
            if(arr[loc]>arr[right_ptr]){
                swap(arr[loc],arr[right_ptr]);
                loc=right_ptr;
            }
            if(arr[loc]<arr[right_ptr]){
                right_ptr--;
            }
        }
        while(loc>left_ptr){
            if(arr[loc]<arr[left_ptr]){
                swap(arr[loc],arr[left_ptr]);
                loc=left_ptr;
            }
            if(arr[loc]>arr[left_ptr]){
                left_ptr++;
            }
        }
    }
    return;
}



int main(){
    int arr[] = {7, 11, 14, 6, 9, 4, 3, 12}, size=8;
    quick(arr,size);
    for(int i=0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}