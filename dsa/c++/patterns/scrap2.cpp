//prefix sum/ruinng sum in the same array without creating a new array 
#include<iostream>
#include<vector>
using namespace std;

void prefixsum(vector<int> &v, int &size){
    for(int i=1; i<size; i++){
        v[i]+=v[i-1];
    }
    return;
}
void suffixsum(vector<int> &v, int &size){
    for(int i=size-2; i>=1; i--){
        v[i]+=v[i+1];
    }
}
int main(){
    int size;
    cin>>size;
    vector<int> v;
    for (int i=0; i<size; i++){
        int ele;
        cin>>ele;
        v.push_back(ele);
    }
    suffixsum(v,size);
    
    for(int i=0;i<size; i++){
        cout<<v[i]<<" ";
    }
    return 0;
}