#include<bits/stdc++.h>
#define ll long long
using namespace std;


long double power(long double a, ll b) {
    long double res = 1;
    while (b) {
        if (b & 1) res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}

int main(){
    long double p = 0.5;
    long double ans = 0;
    for(int i = 10; i<=20; i++){
        ans += power(p, i);
    }
    cout<<ans<<endl;
}