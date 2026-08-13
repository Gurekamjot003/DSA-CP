#include<iostream>
using namespace std;

class swapr{
    public:
        swapr(int& a, int &b){
            int temp=a; 
            a=b;
            b=temp;
        }
};

int main(){
    int a=4, b=5;
    cout<<"Value of a is and b is "<<a<<" and "<<b<<endl;
    swapr(a,b);
    cout<<"Value of a is and b is "<<a<<" and "<<b<<endl;
    return 0;
}