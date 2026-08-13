// Given an array of integers, print sums of all subsets in it. Output sums can be
// printed in any order.
// Input : arr[] = {2,3}
// Output :
// 0 2 3 5
// Input : arr[] = {2,4,5}
// Output :
// 0 2 4 5 6 7 9 11

#include<iostream>
#include<vector>
using namespace std;

// int sum(vector<int> arr){
//     int ans = 0;
//     for(auto num: arr) ans+=num;
//     return ans;
// }
void subsetSum(vector<int> arr, int i, int sum){
    
    if(i == arr.size()) {
        cout<<sum<< " ";
        return;
    }
    subsetSum(arr, i+1, sum);
    subsetSum(arr, i+1, sum+arr[i]);
}


int main(){
    vector<int> arr1 = {2,3}, arr2 = {2,4,5};
    subsetSum(arr2, 0, 0);
    return 0;
}