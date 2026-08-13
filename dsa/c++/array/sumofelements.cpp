#include<iostream>
using namespace std;

int main(){
    int array[]= {10,22,11,23};
    int sum=0;
    int size=sizeof(array)/sizeof(array[0]);
    for(int idx=0; idx<size; idx++){
        sum+=array[idx];
    }
    cout<<sum;
    return 0;
}