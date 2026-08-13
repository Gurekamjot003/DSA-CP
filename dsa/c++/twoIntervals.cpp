//input 2 ranges and print out the numbers range common in the 2 ranges
//for eg 3 5 2 4, o/p = 3 4

#include<iostream>
using namespace std;

int main(){
    int l1, r1, l2, r2, l3=0, r3=0;         // i = 3
    cin>>l1>>r1>>l2>>r2;                // j = 3
    for(int i=l1; i<=r1; i++){          // l3= 3
        for(int j= l2; j<=r2; j++){     // r3=
            if(i==j){
                l3=j;
                goto here;
            }
        }
    }
    here:
    r1>r2? r3=r2 : r3 = r1;
    if(l3!=0){
        cout <<l3<<" "<<r3;
    }
    else{
        cout<< -1;
    }
    return 0;
}