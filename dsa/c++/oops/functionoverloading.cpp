#include<iostream>
using namespace std;
class add{
    
public:
    int sum(int x,int y){
        return x+y;
    }
    int sum(int x, int y, int z){
        return x+y+z;
    }
    float sum(float x, float y){
        return x+y;
    }
};

int main(){
    add a;
    cout<<a.sum(5,4)<<" ";
    cout<<a.sum(5,4,3)<<" ";
    cout<<a.sum(float(4.3),float(3.2));
    return 0;
}