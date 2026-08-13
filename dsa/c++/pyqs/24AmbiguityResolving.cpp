//wap to resolve ambiguity in single level inheritance

#include<iostream>
using namespace std;

class base{
    public:
    void print(){
        cout<<"base class1"<<endl;
    }
};

class base2{
    public:
    void print(){
        cout<<"base class2"<<endl;
    }
};
class derived: public base, public base2{
    public: 
    void print(){
        base::print();
    }
};

int main(){
    derived der;
    der.print();
    
    return 0;
}