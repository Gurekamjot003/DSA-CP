#include<iostream>
using namespace std;

int main(){
    int dec, bin=0,prod=1;
    cin>>dec;
    while(dec>0){
        int dig=dec%2;
        bin+=dig*prod;
        prod*=10;
        dec/=2;
    }
    cout<<bin;
    return 0;
}