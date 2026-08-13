// tc = O(n^2)

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
    arr = {10, 50, 40, 30, 20};
    int n = arr.size();
    for(int i = 0; i<n-1; i++){
        bool flag = false;
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(flag == false) break;
    }
    for(auto n: arr){
        cout<<n<<" ";
    }
    return 0;
}