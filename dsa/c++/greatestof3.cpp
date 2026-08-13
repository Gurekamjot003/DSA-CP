#include<iostream>
using namespace std;

int main(){
    int n1,n2,n3;
    cout<<"Enter first no: ";
    cin>>n1;
    cout<<"Enter second no: ";
    cin>>n2;
    cout<<"Enter third no: ";
    cin>>n3;
    if(n1>n2 && n1>n3){
        cout<<n1<<" is largest";
    }
    else if(n2>n1 && n2>n3){
        cout<<n2<<" is largest";
    }
    else{
        cout<<n3<<" is largest";
    }
    return 0;
}