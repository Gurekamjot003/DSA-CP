#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> & arr, int ind, int size){
    if(ind == size) return;
    cout<<arr[ind]<<" ";
    print(arr, ind+1, size);
}

int main(){
    vector<int> arr = {6,1, 10, 5,3};
    print(arr, 0, arr.size());
    return 0;
}