//n = 5, sum = 1-2+3-4+5 = 3

#include<iostream>
using namespace std;

int sum(int n){
    if(n<=1) return 1;
    if(n%2==0) return -n + sum(n-1);
    else return n+sum(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<sum(n);
    return 0;
}