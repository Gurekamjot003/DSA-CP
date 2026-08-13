//Example of exception handling

#include<iostream>
using namespace std;

class division{
    int a; int b;
    public:
    void setData(int x, int y){
        a=x; b=y;
    }
    float div(){
        try{
            if(b==0){
                throw 10;
            }
            else{
                return float(a)/float(b);
            }
        }
        catch(int ex){
            cout<<"Division by zero"<<endl;     
        }
    }
};

int main(){
    division d;
    d.setData(10,2);
    cout<<d.div()<<endl;
    division d2;
    d2.setData(10,0);
    cout<<d2.div()<<endl;
    return 0;
}