// could hv used bubble sort for solving only by sorting algos

#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
    arr = {0, 5, 0, 3, 42};
    int back = arr.size()-1;
    while(arr[back] == 0) back--;
    int ptr = back - 1;
    while(ptr >=0){
        if(arr[ptr] == 0){
            swap(arr[back], arr[ptr]);
            back--;
        }
        ptr--;
    }
    for(auto n: arr) cout<<n<<" ";
    return 0;
}