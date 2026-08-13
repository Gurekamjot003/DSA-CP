#include<iostream>
using namespace std;

int power(int p, int q){
    if(q==0) return 1;
    return p * power(p, q-1);
}

int powerOptimised(int p, int q){
    if(q==0) return 1;
    if(q%2 == 0) {
        int result = powerOptimised(p, q/2);
        return result*result;
    }
    else {
        int result = powerOptimised(p, (q-1)/2);
        return p*result*result;
    }
}
int main(){
    int p, q;
    cin>>p>>q;
    cout<<powerOptimised(p,q);
    return 0;
}