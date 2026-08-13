#include<iostream>
using namespace std;

int main(){
    int num;
    cout<<"enter a number"<<endl;
    cin>>num;
    if((num%5==0)||(num%3==0)){
        cout<<num;
    }
    return 0;
}