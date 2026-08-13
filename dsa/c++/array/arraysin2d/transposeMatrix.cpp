//transpose of a martix
#include<iostream>
using namespace std;

int main(){
    //inputting a 2d array / matrix
    cout<<"Enter no of rows and columns in a matrix: ";
    int r,c; cin>>r>>c;
    cout<<"Enter the elements: ";
    int mat[r][c];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>mat[i][j];
        }
    }
    //showing real matrix
    cout<<"Matrix: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    //creating transpose of that matrix
    int ans[c][r];
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            ans[i][j]=mat[j][i];
        }
    }
    //returning the answer
    cout<<"Transpose matrix: "<<endl;
    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0; 
}