#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    cout<<"List: ";
    for(int i=0; i<5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Enter rotational no for the list: ";
    int k;
    cin>>k;
    for(int i=0; i<k; i++){
        int temp=arr[4];
        for(int j=3; j>=0; j--){
            arr[j+1]=arr[j];
        }
        arr[0]=temp;
    }
    cout<<"Rotated List: ";
    for(int i=0; i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}