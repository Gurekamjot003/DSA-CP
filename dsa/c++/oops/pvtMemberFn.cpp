#include<iostream>
using namespace std;
class value{
private:
    int a,b;
    void getdata();
public:
    void show();
};
void value::getdata(){
    cout<<"Enter 1st no.: ";
    cin>>a;
    cout<<"Enter 2nd no.: ";
    cin>>b;
}
void value::show(){
    getdata();
    cout<<"Two no.s are "<<a<< " and "<<b;
}
int main(){
    value v;
    
    v.show();
    return 0;
}