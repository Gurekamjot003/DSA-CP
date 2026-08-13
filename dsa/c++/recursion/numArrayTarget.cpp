// Given an array of n integers and a target value x.Print whether x exists in the
// array or not.
// Constraints :
// 0<=n<=1e6, -1e8<= x <= 1e8, -1e8 <= a[i] <= 1e8

// Input1 : n = 8, x = 14, array = [4, 12, 54, 14, 3 , 8, 6, 1]
// Output1 : Yes

// Input2: n = 1, x = 9, array = [2]
// Output2 : No

#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int> arr, int i, int target){
    if(i == arr.size()) return false;
    if(arr[i] == target) return true;
    else return search(arr, i+1, target);
}

int main(){
    vector<int> arr = {4, 12, 54, 14, 3 , 8, 6, 1};
    int x = 15;
    int n = 8;
    if(search(arr, 0, x)) cout<<"Yes";
    else cout<<"No";
    return 0;
}