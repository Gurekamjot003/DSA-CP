//write an example to illustrate different access specifiers in cpp

#include<iostream>
using namespace std;

class A{
    private:
        int a=1;
    protected:
        int b=2;
    public:
    int c=3;
    void displayA(){
        cout <<"Class a"<<endl;
        cout<<a<<endl<<b<<endl<<c<<endl;        //all members are accessible in A
    }
};

class B: private A{
    public:
        void displayB(){
            cout<<"Class b"<<endl;
            //cout<<a<<endl;    //private member is not accessible
            cout<<b<<endl;      //protected member becomes private 
            cout<<c<<endl;      //public member becomes private
        }
};

class C: protected A{
    public:
        void displayC(){
            cout<<"Class c"<<endl;
            //cout<<a<<endl;        //private member is note accessible
            cout<<b<<endl;          //protected member remains protected
            cout<<c<<endl;          //public member becomes protected
        }
};

class D: public A{
    public:
        void displayD(){
            cout<<"Class d"<<endl;
            // cout<<a<<endl;      //private member not accessible
            cout<<b<<endl;          //protected member remains protected
            cout<<c<<endl;          //public member remains public
        }
};

int main(){
    A a;
    a.displayA();
    B b;
    b.displayB();
    C c;
    c.displayC();
    D d;
    d.displayD();
    return 0;
}