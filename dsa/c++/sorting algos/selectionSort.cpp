// max swaps = n
// tc = O(n^2)
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
    arr = {5, 1,3,2,4};
    int end = arr.size();
    for(int start = 0; start<end; start++){
        int minIndex = start;
        for(int j = start+1; j<end; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != start) swap(arr[minIndex], arr[start]);
    }

    for(auto n: arr) cout<<n<<" ";
    return 0;
}