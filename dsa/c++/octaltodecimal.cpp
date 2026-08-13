//octal to decimal
#include<iostream>
using namespace std;

int main(){
    int octno,prod=1, dec=0;
    cout<<"Enter an octal no: ";
    cin>>octno;
    int temp=octno;
    while(temp>0){
        int lastdig=temp%10;
        dec+=lastdig*prod;
        prod*=8;
        temp/=10;
    }
    cout<<dec;
    return 0;
}