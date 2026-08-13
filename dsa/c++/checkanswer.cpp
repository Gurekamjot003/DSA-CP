// Given a mathematical expression. The expression will be one of the following expressions:
// A + B = C, A - B = C and A * B = C,where 
// A, B, C are three numbers, 
// S is the sign between 
// A and B, and Q the '=' sign
// Print "Yes" If the expression is Right, Otherwise print the right answer of the expression right answer of the expression.

#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    char s, q;
    here:
    cin>>a>>s>>b>>q>>c;
    switch (s)
    {
    case '+':
        if(c==(a+b)){
            cout<<"Yes";
        }
        else{
            cout<<a+b;
        }
        break;
    case '-':
        if(c==(a-b)){
            cout<<"Yes";
        }
        else{
            cout<<a-b;
        }
        break;
    case '*':
        if(c==(a*b)){
            cout<<"Yes";
        }
        else{
            cout<<a*b;
        }
        break;
    
    default:
        cout<<"Enter only +, - or * case"<<endl;
        goto here;
        break;
    }    
    return 0;
}