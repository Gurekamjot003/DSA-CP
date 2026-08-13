#include<iostream>
using namespace std;

int main(){
    int n=5;
    int arr[n]={1,2,3,4,5};
    cout<<"array= ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    int j=n, k, item;
    cout<<"Enter element to insert and then its position: ";
    cin>>item>>k;
    while(j>=k){
        arr[j+1]=arr[j];
        j--;
    }
    arr[k]=item;
    n+=1;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}