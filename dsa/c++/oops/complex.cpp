#include<iostream>
using namespace std;

class complex
{
private:
    int a;
    int b;
public:
    void setdata(int v1, int v2){
        a=v1;   b=v2;
    }
    void getdata(){
        cout<<"The complex number is "<<a<<" + "<<b<<"i"<<endl;
    }
    void sumOfComplex(complex c1, complex c2){
        a=c1.a+c2.a;
        b=c1.b+c2.b;
    }
};

int main(){
    int d,e,f,g;
    cin>>d>>e>>f>>g;
    complex c3,c4;
    c3.setdata(d,e);
    c4.setdata(f,g);
    c3.getdata();
    c4.getdata();
    complex c5;
    c5.sumOfComplex(c3,c4);
    c5.getdata();
    return 0;
}