#include<iostream>
using namespace std;

int main(){
    int n1,n2;
    cout<<"Enter 2 no.s: ";
    cin>>n1>>n2;
    char op;
    cout<<"Enter operator from +, -, *, /, %: ";
    cin>>op;
    switch(op)
    {
        case '+':
            cout<<n1+n2;
            break;
        case '-':
            cout<<n1-n2;
            break;
        case '*':
            cout<<n1*n2;
            break;
        case '/':
            cout<<n1/n2;
            break;
        case '%':
            cout<<n1%n2;
            break;
        default:
            cout<<"Enter only given operators";
    }
    return 0;
}