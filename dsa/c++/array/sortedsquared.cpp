//given an array sorted in non-decreasing order, return an array of the squares of each no sorted in non-decreasing order
#include<iostream>
using namespace std;

int main(){
    int arr[]={-10,-3,4,5,6}, size=5;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(abs(arr[i])>abs(arr[j])){
                swap(arr[i],arr[j]);
            }
        }
    }

    for(int i=0; i<size; i++){
        arr[i]=arr[i]*arr[i];
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}