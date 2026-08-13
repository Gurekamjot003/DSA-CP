#include<iostream>
using namespace std;

int main(){
    int n=5,arr[n]={1,2,3,4,5},k;
    cout<<"Array: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Enter the index of element u want to delete";
    cin>>k;
    while(k<n){
        arr[k]=arr[k+1];
        k++;
    }
    n--;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}