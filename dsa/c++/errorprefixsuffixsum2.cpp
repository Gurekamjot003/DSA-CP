#include<iostream>
#include<vector>
using namespace std;

//calculates sum by prefix sum
bool checkprefixsum(vector<int> v, int x, int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=v[i];
    }
    for(int i=1;i<x; i++){
        v[i]+=v[i-1];
    }
    int suffixsum=sum-v[n-1];
    return v[n-1]==suffixsum;
}

int main(){
    vector<int> v;          //creating vector v and adding elements in it
    cout<<"Enter no. of elements: ";
    int n; cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        int x; cin>>x;
        v.push_back(x);
    }
         //temporary vector
    //checking if prefix sum = total sum/2
    for(int x=1; x<n; x++){
        vector<int> temp=v;
        if(checkprefixsum(temp,x,n)){
            cout<<"Sum equals at "<<x;
            break;
        }
    }

    return 0;
}