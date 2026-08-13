#include<iostream>
#include<vector>
using namespace std;

vector<int> combine(vector<int> a1, vector<int> a2){
    int ptr1 = 0, ptr2 = 0;
    vector<int> ans;
    while(ptr1<a1.size() && ptr2 < a2.size()){
        if(a1[ptr1]<a2[ptr2]){
            ans.push_back(a1[ptr1]);
            ptr1++;
        }
        else{
            ans.push_back(a2[ptr2]);
            ptr2++;
        }
    }
    while(ptr1<a1.size()){
        ans.push_back(a1[ptr1]);
        ptr1++;
    }
    while(ptr2<a2.size()){
        ans.push_back(a2[ptr2]);
        ptr2++;
    }
    return ans;
}

void mergeSort(vector<int>& arr){
    if(arr.size() <= 1) return;

    vector<int> array1, array2;
    int mid = arr.size()/2;
    for(int i = 0; i<mid; i++){
        array1.push_back(arr[i]);
    }
    for(int i = mid; i<arr.size(); i++){
        array2.push_back(arr[i]);
    }
     
    mergeSort(array1);
    mergeSort(array2);
    
    arr = combine(array1, array2);
}

int main(){
    vector<int> arr;
    arr = {10,3, 5, 2, 7, 6, 4, 9};
    mergeSort(arr);
    for(auto n: arr){
        cout<<n<<" ";
    }
    return 0;
}