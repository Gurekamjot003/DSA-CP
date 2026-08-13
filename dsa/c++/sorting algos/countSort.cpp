#include<iostream>
#include<vector>
using namespace std;

vector<int> countSort(vector<int> arr){
    vector<int> count;
    for(auto n: arr){
        if(n>=count.size()) count.resize(n+1);
        count[n]++;
    }
    for(int i = 1; i<count.size(); i++){
        count[i] += count[i-1];
    }
    vector<int> ans(arr.size());
    for(int i = arr.size()-1; i>=0; i--){
        count[arr[i]]--;
        ans[count[arr[i]]] = arr[i];
    }
    return ans;
}

int main(){
    vector<int> arr;
    arr = {5, 3, 2, 3, 2};
    vector<int> sorted = countSort(arr);
    for(auto n: sorted) cout<<n<<" ";
    return 0;
}