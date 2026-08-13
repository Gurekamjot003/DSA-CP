// There are N stones, numbered 1,2,...,N. For each i (1<=i<=N), the height of Stone i is hi.There
// is a frog who is initially on Stone 1. He will repeat the following action some number of
// times to reach Stone N:
// If the frog is currently on Stone i, jump to Stone i+l or Stone i+2. Here, a cost of |hi - hj |
// is incurred, where j is the stone to land on.
// Find the minimum possible total cost incurred before the frog reaches Stone N.
// Input n = 4
// arr[] = 10 30 40 20
// Output= 30

#include<iostream>
#include<vector>
#include<math.h>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int minCost(vector<int> arr, int i ){
    if(i == arr.size()-1) return 0;
    if(i == arr.size() - 2) return abs(arr[i] - arr[i+1]);
    return min(abs(arr[i+1]-arr[i]) + minCost(arr, i+1), abs(arr[i]-arr[i+2]) + minCost(arr, i+2));
}

int main(){
    // int n;
    // cin>>n;
    // vector<int> arr(n);
    // for(int i =0; i<n; i++){
    //     cin>>arr[i];
    // }

    vector<int> arr = {10, 10}; int n = 2;



    cout<<minCost(arr, 0);


    return 0;
}
