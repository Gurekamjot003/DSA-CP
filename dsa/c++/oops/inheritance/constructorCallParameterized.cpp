#include<iostream>
using namespace std;

class Parent{
    public:
        Parent(int x){
            cout<<"Parent class"<<endl;
        }
};

class Child : public Parent{
    public: 
        Child(int y) : Parent(y){
            cout<<"Child class"<<endl;
        }
};

int main(){
    Child c1(10);
    return 0;
}