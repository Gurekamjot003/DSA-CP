// print numbers upto n without loop

#include<iostream>
using namespace std;

void print(int i, int n){
    if(i == n) return;
    cout<<i+1<<" ";
    print(i+1, n);
}

int main(){
    int n; 
    cin>>n;
    print(0,n);
    return 0;
}