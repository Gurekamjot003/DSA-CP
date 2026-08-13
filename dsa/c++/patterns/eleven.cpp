/*
1234554321
1234**4321
123****321
12******21
1********1
*/

#include<iostream>
using namespace std;

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if((i+j) >= n) cout<<"*";
            else cout<<j+1;
        }
        for(int j = n; j>=1; j--){
            if((i+j) >=n+1) cout<<"*";
            else cout<<j;
        }
        cout<<endl;
    }
    return 0;
}
