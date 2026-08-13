//linear search
#include<iostream>
using namespace std;

int main(){
    cout<<"Enter no of elements in list: ";
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter "<<i<<" element: ";
        cin>>arr[i];
    }
    cout<<"Entered list is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Enter an element to search in the list: ";
    int x,loc=-1;
    cin>>x;
    for(int i=0; i<n; i++){
        if(arr[i]==x){
            loc=i;
            cout<<"Element is present at index: "<<loc;
        }
    }
    if(loc==-1){
        cout<<"Element not present in list";
    }
    return 0;
}