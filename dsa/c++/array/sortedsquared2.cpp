//given an array sorted in non-decreasing order, return an array of the squares of each no sorted in non-decreasing order
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    int arr[]={-10,-3,2,4,6}, size=5, left_ptr=0, right_ptr=size-1;
    vector<int> v;
    while(left_ptr<right_ptr){
        if(abs(arr[left_ptr])>abs(arr[right_ptr])){
            v.push_back(pow(arr[left_ptr++],2));
        }
        if(abs(arr[left_ptr])<abs(arr[right_ptr])){
            v.push_back(pow(arr[right_ptr--],2));
        }
    }
    reverse(v.begin(),v.end());
    for(int i=0; i<size; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}