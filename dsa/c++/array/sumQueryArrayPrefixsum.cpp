//claculate the sum of array elements from a left pointer to a right pointer
#include<iostream>
using namespace std;
//prefix sum function
int prefixsum(int arr[], int n){
    int psarr[n];
    psarr[0]=arr[0];
    for(int i =1; i<n; i++){
        psarr[i]=psarr[i-1]+arr[i];
    }
    return psarr[n-1];              //returns last element of array(total sum)
}

int main(){
    //inputting array
    cout<<"Enter no of elements in array: ";
    int n; cin>>n;
    int arr[n];
    cout<<"Enter the elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    //inputting no of queries
    cout<<"Enter no of queries: ";
    int q; cin>>q;

    while(q--){
        cout<<"Enter the left and right pointer: ";
        int l,r; cin>>l>>r;
        if(l=1){        //simple prefix fn upto element r
            cout<< prefixsum(arr,r)<<endl;  //returning prefix array upto r
        }
        else{       //value of l>1
            cout<< prefixsum(arr,r)-prefixsum(arr,l-1)<<endl;   
            //prefix sum upto r - prefix sum upto l-1 will give the sum
        }
    }
    return 0;
}