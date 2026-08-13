#include<iostream>
#include<vector>
using namespace std;

vector<int> countSort(vector<int> arr, int mul){
    vector<int> count(10);
    for(auto n: arr){
        count[(n%mul)/(mul/10)]++;
    }
    for(int i = 1; i<count.size(); i++){
        count[i] += count[i-1];
    }
    vector<int> ans(arr.size());
    for(int i = arr.size()-1; i>=0; i--){
        count[(arr[i]%mul)/(mul/10)]--;
        ans[count[(arr[i]%mul)/(mul/10)]] = arr[i];
    }
    return ans;
}

void radixSort(vector<int> & arr){
    long long maxVal = INT_MIN;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] > maxVal) maxVal = arr[i];
    }
    int noDigits = to_string(maxVal).size();
    int mul = 10;
    for(int i = 0; i<noDigits; i++){
        arr = countSort(arr, mul);
        mul*=10;
    }
}

int main(){
    vector<int> arr;
    arr = {170, 45, 75, 90, 802, 2};
    radixSort(arr);
    for(auto n: arr) cout<<n<<" ";
    return 0;
}