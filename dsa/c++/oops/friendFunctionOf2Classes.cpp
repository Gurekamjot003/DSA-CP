#include<iostream>
using namespace std;

class Y;

class X{
    int data;
    public:
        void setValue(int value){
            data=value;
        }
    friend void add(X, Y);
};

class Y{
    int num;
    public:
        void setNum(int value){
            num=value;
        }
    friend void add(X, Y);
};

void add(X a, Y b){
    cout<<a.data+b.num;
}

int main(){
    X x1; Y y1;
    x1.setValue(5);
    y1.setNum(4);
    add(x1,y1);
    return 0;
}