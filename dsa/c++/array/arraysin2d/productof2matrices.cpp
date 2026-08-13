#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    //inputting matrix 1
    cout<<"Enter no of rows and columns in m1: ";       
    cin>>a>>b;
    int m1[a][b] ;
    cout<<"Enter values: ";
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cin>>m1[i][j];
        }
    }
    //inputting matrix 2
    cout<<"Enter no of columns in m2: ";        //no of columns of m1 has to be equal to no of rows of m2
    cin>>c;                                     //inputting only no of columns
    int m2[b][c];
    cout<<"Enter values: ";
    for(int i=0; i<b; i++){
        for(int j=0; j<c; j++){
            cin>>m2[i][j];
        }
    }
    //solution matrix ans and setting all elements as 0
    int ans[a][c];
    for(int i=0; i<a; i++){
        for(int j=0; j<c; j++){
            ans[i][j]=0;
        }
    }
    //setting ans elements as product of m1 and m2
    for(int i=0; i<a; i++){
        for(int j=0; j<c; j++){
            for(int k=0; k<b; k++){
                ans[i][j]+=m1[i][k]*m2[k][j];
            }
        }
    }
    //outputting answer
    cout<<"Product ="<<endl;
    for(int i=0; i<a; i++){
        for(int j=0; j<c; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}