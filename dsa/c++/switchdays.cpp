#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    switch (n)
    {
    case 1 :
       cout<<"monday";
       break;

    case 2 :
        cout<<"tuesday";
        break;

    case 3 :
        cout<<"wed";
        break;
    
    case 4 :
        cout<<"thu";
        break;
    
    case 5 :
        cout<<"fri";
        break;

    case 6 :
        cout<<"sat";
        break;
    
    default:
        cout<<"sun";
        break;
    }
    return 0;
}