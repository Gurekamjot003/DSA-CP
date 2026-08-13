#include<iostream>
#include <math.h>
#include<cmath>
using namespace std;

int sumOfCubes(int n){
    if(n<=0) return 0;
    int lastdig = n%10;
    return pow(lastdig,3) + sumOfCubes(n/10);
}

int main(){
    int n; cin>>n;
    if(sumOfCubes(n) == n) cout<<"yes";
    else cout<<"no";
    return 0;
}