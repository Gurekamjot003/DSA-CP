#include<iostream>
using namespace std;
class abc{
    int x;
public:
    
    void set(int n){
        x=n;
    }
    int get(){
        return x;
    }
};

int main(){
    abc z;
    z.set(5);
    cout<<z.get();

    return 0;
}