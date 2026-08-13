//     1
//    12
//   123
//  1234
// 12345

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 1; i<=n; i++){
        for(int j = n-i; j>0; j--){
            cout<<" ";
        }
        for(int j = 0; j<i; j++){
            cout<<j+1;
        }
        cout<<endl;
    }
    return 0;
}