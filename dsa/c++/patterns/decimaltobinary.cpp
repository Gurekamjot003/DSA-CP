#include<iostream>
using namespace std;

int main(){
   int dec, bin=0, prod=1024;
   cin>> dec;
   int temp=dec;
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
   cout<<bin;
    return 0;
}