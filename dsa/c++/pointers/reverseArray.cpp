#include<iostream>
using namespace std;

void reverse(int ptr_arr[], int* ptr_n){
    int left =0 , right = *ptr_n-1;
    while(left<=right){
        swap(ptr_arr[left], ptr_arr[right]);
        left++; right--;
    }

}

int main(){
    int *ptr_n = new int;
    cin>>*ptr_n;
    int *ptr_arr = new int[*ptr_n];  
    for(int i=0; i<*ptr_n; i++)
        cin>>ptr_arr[i];
    cout<<"Before Reversing: "<<'\n';
    for(int i=0; i<*ptr_n; i++)
        cout<<ptr_arr[i]<<" ";
    cout<<"\nAfter Reversing: \n";
    reverse(ptr_arr, ptr_n);
    for(int i=0; i<*ptr_n; i++)
        cout<<ptr_arr[i]<<" ";    
    return 0;
}