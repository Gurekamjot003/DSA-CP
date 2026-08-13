#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter value: ";
    cin>>n;
    int temp=n;
    for(int i=1; i<=n; i++){
        for(int j=temp; j>1; j--){
            cout<<" ";
        }
        for(int k=0; k<(2*i-1); k++){
            cout<<(char)(k+65);
        }
        cout<<endl;
        temp--;
    }
    for(int i=n-1; i>0; i--){
        for(int j=i; j<n; j++){
            cout<<" ";
        }
        for(int k=0; k<2*i-1; k++){
            cout<<(char)(k+65);
        }
        cout<<endl;
    }
    return 0;
}