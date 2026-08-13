//binary search
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Binary search program\nEnter no of elements in list: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cout<<"Enter value of "<<i<<" element: ";
        cin>>arr[i];

    }
    cout<<"Entered list is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    int x, start=0, end=n, loc=-1;
    cout<<endl<<"Enter element to search in list: ";
    cin>>x;
    while(start<=end && loc==-1){
        int mid=(start + end)/2;
        if(arr[mid]==x){
            loc=mid;
            cout<<"Element is present at location: "<<loc;
        }
        else if(arr[mid]>x){
            end=mid-1;
        }
        else{
            start = mid+1;
        }
    }
    if(loc==-1){
        cout<<"Element not present in list";
    }

    return 0;
}