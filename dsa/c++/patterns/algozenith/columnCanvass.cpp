// *       *       *
//  *     * *     * *
//   *   *   *   *   ..... 
//    * *     * *
//     *       *

#include<iostream>
using namespace std;

int main(){
    int rows=5, columns=30;
    for(int i=0; i<5; i++){
        for(int j=0; j<columns; j++){
            if(i==j%8 or i+j%8==8){
                cout<<"*";
            }
            else
                cout<<" ";
        }
        cout<<'\n';
    }
    return 0;
}