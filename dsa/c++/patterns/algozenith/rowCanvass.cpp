/*
*********
 *******
  *****
   ***
    * 
*********
 *******
  *****
   ***
    * 
*********
 *******
  *****
   ***
    * 
*/

#include<iostream>
using namespace std;

int main(){
    int rows= 30, columns=9;
    for(int i=0; i<rows; i++){
        for(int j=0; j<columns; j++){
            if(i%5<=j and i%5+j<=8)
                cout<<"*";
            else
                cout<<" ";
        }cout<<endl;
    }
    return 0;
}