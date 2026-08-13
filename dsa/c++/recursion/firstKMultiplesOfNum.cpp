#include<iostream>
using namespace std;

void print(int k, int num){
    if(k==0) return;
    print(k-1, num);
    cout<<" "<<num*k;
}

int main(){
    int num;
    cin>>num;
    int k;
    cin>>k;
    print(k,num);
    return 0;
}