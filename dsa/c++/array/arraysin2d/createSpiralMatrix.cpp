#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n][n], i=1, top = 0, left = 0, right = n-1, bottom = n-1, j;

    while(i<=n*n){
        for(j=left; j<=right; j++)
            arr[top][j] = i++;
        top++;
        for(j=top; j<=bottom; j++)
            arr[j][right] = i++;
        right--;
        for(j=right; j>=left; j--)
            arr[bottom][j] = i++;
        bottom--;
        for(j=bottom;j>=top;j--)
            arr[j][left] = i++;
        left++;
    }
    for(i = 0; i<n; i++){
        for(j=0; j<n; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}