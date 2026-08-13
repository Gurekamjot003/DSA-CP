//decimal value containing a point into binary
#include<iostream>
#include<math.h>
#include<cmath>
#include<iomanip>
using namespace std;

//for before the point
long int binary(int n){
   long int bin=0, prod=1024;
   long int temp=n;
   while(prod>0){  //if 1024>decimal no then it will sub 1024 from it, division by 2 of prod will take place until it evaluates to 0
    if(temp>=prod){
        bin=bin*10+1;   //1 will be displayed if it is greater
        temp-=prod;
    }
    else{
        bin=bin*10+0;  // otherwise 0 will be displayed
    }
    prod/=2;
   }
   return bin;
}

//for after the point
long double binad(double n){
    long double bin=0,prod=0.5, no=0.1;  
    long double temp=n;
    while(temp>0){
        if(temp>=prod){
            bin+=no;
            temp-=prod;
        }
        no/=10;                     //either 1 or 0 will be added to the binary no after the point
        prod/=2;                    //prod which is 0.5 will get halved every time as in binary
        if(temp==0){
            break;
        }
    }
    return bin;

}
int main(){
    long double n,ni,nd;
    cout<<"Enter a decimal no to be converted into binary: ";
    cin>>n;
    nd=modf(n, &ni);                    //separating integral and fraction value
    long double ans=binary(ni)+binad(nd);  //adding both values
    cout<<setprecision(20)<< ans;
    return 0;
}