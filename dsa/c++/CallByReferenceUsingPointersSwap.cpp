#include<iostream>
using namespace std;

void swapPtr(int* a, int* b){
    int temp= *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 4,b=5;
    cout<<"Value of a and b is: "<<a<<" and "<<b<<endl;
    swapPtr(&a,&b);
    cout<<"Value of a and b is: "<<a<<" and "<<b<<endl;

    return 0;
}