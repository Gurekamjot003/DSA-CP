//Explain virtual and pure virtual function

#include<iostream>
using namespace std;

class Base{
    public:
        virtual void print(){
            cout<<"Print Base class"<<endl;
        }
        void show(){
            cout<<"Show Base class"<<endl;
        }
        virtual void display(){
            cout<<"Display Base class"<<endl;
        }
        virtual void get()=0;
};

class derived : public Base{
    void print(){
        cout<<"Print derived class"<<endl;
    }
    void show(){
        cout<<"Show derived class"<<endl;
    }
    void get(){
        cout<<"Get derived class"<<endl;
    }
};

int main(){
    Base* bptr;  
    derived d;
    bptr=&d;
    bptr->print();
    bptr->show();
    bptr->display();
    bptr->get();
    
    return 0;
}