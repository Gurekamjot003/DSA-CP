#include<iostream>
using namespace std;

int main() {
    int a,b,c;
    cout<<"enter first value"<<endl;
    cin>>a;
    cout<<"enter second value"<<endl;
    cin>>b;
    //swapping the values with help of variable c
    c=a;
    a=b;
    b=c;
    cout<<"first value :"<<a<<endl;
    cout<<"second valur :"<<b<<endl;

    return 0;
}