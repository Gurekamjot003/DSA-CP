/*
  *
  *
*****
  *
  * 
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter an odd no.: ";
    cin>>n;
    if(n%2!=0){
        int mid=(n+1)/2;
        for(int i=1; i<=n; i++){
            if(i!=mid){
                for(int spaces=1; spaces<mid; spaces++){
                    cout<<" ";
                }
                cout<<"*"<<endl;
            }
            else{
                for(int k=1; k<=n; k++){
                    cout<<"*";
                }
                cout<<endl;
            }
        }
    }
    else{
        cout<<"Enter odd value only";
    }
    return 0;
}