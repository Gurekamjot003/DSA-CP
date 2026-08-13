//Example of default and parameterized contructor in cpp

#include<iostream>
using namespace std;

class base1{
    public:
    base1(){
        cout<<"Base class 1"<<endl;
    }
};

class derived1 : public base1{
    public:
    derived1(){
        cout<<"Derived class 1"<<endl;
    }
};

class base2{
    public:
    base2(int x){
        cout<<"Base class 2"<<endl;
    }
};

class derived2: public base2{
    public: 
    derived2( int x): base2(x){
        cout<<"Derived class 2"<<endl;
    }
};

int main(){
    derived1 d1;
    derived2 d2(5);
    
    return 0;
}