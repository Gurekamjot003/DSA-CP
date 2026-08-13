#include<iostream>
using namespace std;

void swapRef(int &a, int &b){
    int temp =a;
    a=b;
    b=temp;
}

int main(){
    int a=4,b=5;
    cout<<"Value of a and b is: "<<a<<" and "<<b<<endl;
    swapRef(a,b);
    cout<<"Value of a and b is: "<<a<<" and "<<b<<endl;
    return 0;
}