//Example of operator overloading

#include<iostream>
using namespace std;

class unary{
    int a; int b;
    public:
        void setData(int x,int y){
            a=x; b=y;
        }
        void operator-(){
            a=-a;
            b=-b;
        }
        void display(){
            cout<<a<<endl<<b<<endl;
        }
};

int main(){
    unary a;
    a.setData(-10,20);
    a.display();
    -a;
    a.display();
    
    return 0;
}