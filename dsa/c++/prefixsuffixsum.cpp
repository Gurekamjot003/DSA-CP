//if prefix sum of a subarray is equal to the suffix sum of 
//rest of array
#include<iostream>
using namespace std;
void prefixsum(int arr[], int size){    //alters original array 
    for(int i=1; i<size; i++){          //to prefix sum array
        arr[i]+=arr[i-1];
    }
    return;
}
void suffixsum(int arr[], int size){
    for(int i=size-2; i>=0; i--){       //alters original array 
        arr[i]+=arr[i+1];               //to suffix sum array
    }
    return;
}
int main(){
    //taking input array from user of size n
    int n;
    cout<<"Enter no of element to be in array: ";
    cin>>n;
    cout<<"Enter the elements: ";
    int arr[n],size=sizeof(arr)/sizeof(arr[0]);
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    //following for loop will create subarrays with variable sizes
    for(int i=1; i<size; i++){
        cout<<"Set no. "<<i<<endl;
        int subarr1[i], subarr2[6-i];   //2 sub arrays

        //filling values in subarrary 1 and returning its elements
        cout<<"Subarray 1: "<<endl;
        for(int j=0; j<i; j++){         
            subarr1[j]=arr[j];
            cout<<subarr1[j]<<" ";
        }
        cout<< endl;
        
        //returning prefix sum of subarray 1
        prefixsum(subarr1,i);       //calling function
        cout<<"Prefix sum array of subarray 1: "<<endl;
        for(int j=0; j<i; j++){
            cout<<subarr1[j]<<" ";
        }
        cout<<endl;
        

        //filling values in subarray 2 and returning its elements
        cout<<"Subarray 2: "<<endl;
        int k=0;
        for(int j=i; j<size; j++){
            subarr2[k]=arr[j];
            cout<<subarr2[k++]<<" ";
        }
        cout<<endl;
       
       //returning suffix sum of subarray 2
        suffixsum(subarr2,size-i);      //calling function
        cout<<"Suffix sum array of subarray 2: "<<endl;
        for(int j=0; j<(size-i); j++){
            cout<<subarr2[j]<<" ";
        }
        cout<<endl;

        //applying required condition
        if(subarr1[i-1]==subarr2[0]){
            cout<<"sum equals at "<<i;  
            break;          //program will not go any further
        }
        cout<<endl;

    }
    return 0;
}