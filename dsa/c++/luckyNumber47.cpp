#include<iostream>
using namespace std;

int main(){
    int a, b,flag=0;
    cin>>a>>b;
    for(int i=a; i<=b; i++){
        int temp =i, flag2=0 ;
        while(temp>0){
            int lastdig= temp%10;
            if(lastdig != 4 && lastdig != 7){
                flag2 = 1;
            }
            temp/=10;
        }
        if(flag2==0){
            cout<<i<<" ";
            flag =1;
        }
    }
    if(flag==0){
        cout<<"-1";
    }
    return 0;
}