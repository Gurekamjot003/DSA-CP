#include<iostream>
using namespace std;

int main(){
    int array[]={10,20,15,2};
    int size = sizeof(array)/sizeof(array[0]);
    int ele;
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl<<"Enter element which index u want to find: ";
    cin>>ele;
    int idx=-1;
    for(int i=0; i<size; i++){
        if(array[i]==ele){
            idx=i;
            break;
        }
    }
    cout<<idx;
}