//sort an array containing 0s and 1s
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> v;
    int n,ele;
    cout<<"Enter no of elements you want to add in array: ";
    cin>>n;
    cout<<"Enter the elements(only 0s and 1s): ";
    for(int i=0;i<n; i++){
        cin>>ele;
        v.push_back(ele);
    }
    int count0=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==0){
            count0+=1;
        }
    }
    int ans[v.size()];
    for(int i=0;i<count0;i++){
        ans[i]=0;
    }
    for(int i=count0;i<v.size();i++){
        ans[i]=1;
    }
    for(int i=0;i<v.size();i++){
        cout<<ans[i];
    }
    return 0;
}