#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int i, int j){
    int piInd = i;
    int pi = arr[i];
    i++;
    while(i<=j){
        while(pi>=arr[i] && i<=j) i++;
        while(pi<=arr[j] && i<=j) j--;
        if(i<j){
            swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    swap(arr[piInd], arr[j]);
    return j;
}

void quickSort(vector<int> & arr, int i, int j){
    if(j-i<1) return;
    int k = partition(arr, i, j);
    quickSort(arr, i, k-1);
    quickSort(arr, k+1, j);
}


int main(){
    vector<int> arr;
    arr = {10, 3, 9, 1, 7, 5, 2, 4, 8, 6};
    quickSort(arr, 0, arr.size()-1);
    for(auto n: arr) cout<<n<<" ";
    return 0;
}