#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int sumOfElements(vector<int> & arr, int ind, int size){
    if(ind == size) return 0;
    int sum = arr[ind];
    sum+=sumOfElements(arr, ind+1, size);
    return sum;
}

int main(){
    vector<int> arr = {6,1, 10, 5,3};
    cout<< sumOfElements(arr, 0, arr.size());
    return 0;
}