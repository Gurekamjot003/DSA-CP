#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n = 3, m = 4;
    int arr[n][m] = {{1,2,3,4},{5,6,7,8},{9, 10, 11, 12}}, left= 0, top = 0, right = m-1, bottom = n-1, i;
    while(top<=bottom && left<=right){
        for(i= left; i<=right; i++){
            cout<<arr[top][i]<< " ";
        }
        top++;
        if(top>bottom) break;
        for(i = top; i<=bottom; i++){
            cout<<arr[i][right]<< " ";
        }
        right--; 
        if(left>right) break;
        for(i=right;i>=left;i--){
            cout<<arr[bottom][i]<< " ";
        }
        bottom--;
        if(top>bottom) break;
        for(i=bottom; i>=top; i--){
            cout<<arr[i][left]<< " ";
        }
        left++;
    }
    return 0;
}