#include<iostream>
using namespace std;

int binary(int n){
    int temp = n, bin = 0, mul=1;
    while(temp>0){
        int rem=temp%2;
        bin+=mul*rem;
        mul*=10;
        temp/=2;
    }
    return bin;
}

int binaryShift(int n){
    int temp=n, bn=0, mul =1;
    while(temp>0){
        int lastdig=temp%10;
        if(lastdig==1){
            bn+=mul*lastdig;
            mul*=10;
        }
        temp/=10;
    }   
    return bn;
}

int decimal(int n){
    int temp = n, dec =0, mul=1;
    while(temp>0){
        int lastdig=temp%10;
        dec+=mul*lastdig;
        mul*=2;
        temp/=10;
    }
    return dec;
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        int bn=binary(n);   
        bn= binaryShift(bn);                    
        int dn = decimal(bn);
        cout<<dn<<endl;
    }
    return 0;
}