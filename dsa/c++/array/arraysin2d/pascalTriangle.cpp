//pascals triangle
//1
//11
//121
//1331
//14641...

#include<iostream>
using namespace std;

int main(){
    cout<<"Enter no of rows in pascals triangle: ";
    int n; cin>>n;
    //setting up the 2d array
    int arr[n][n];
    for(int i =0; i<n; i++){        //no of rows
        for(int j=0; j<n; j++){     //no of columns in each row 
            //1st and last element in each row = 1
            if(j==0 || j==i){
                arr[i][j]=1;
            }
            //every element after ith(last) = 0
            else if(j>i && j<n){
                arr[i][j]=0;
            }
            //all elements between 1st and last = element directly above in above row + preceding to that element in above row
            else{
                arr[i][j]=arr[i-1][j]+arr[i-1][j-1];
            }
        }
    }
    //giving the required pascal triangle
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}