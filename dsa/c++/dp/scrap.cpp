#include<iostream>
using namespace std;

int main(){
    cout<<"[";
    for(int i = 0; i<100; i++){
        cout<<"[";
        for(int j= 0; j<100; j++){
            if(i==j) cout<<"100";
            else cout<<"1";
            if((i!=99 && j!= 99) or (i==99 && j!=99)) cout<<",";
        }
        cout<<"]";
        if(i!= 99) cout<<",";
        // cout<<endl;
    }
    cout<<"]";
    return 0;
}