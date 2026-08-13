#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxElement(vector<int> & arr, int ind, int size){
    if(ind == size) return INT32_MIN;
    int maxn = arr[ind];
    maxn = max(maxn, maxElement(arr, ind + 1, size));
    return maxn;
}

int main(){
    vector<int> arr = {6,1, 10, 5,3};
    cout<< maxElement(arr, 0, arr.size());
    return 0;
}