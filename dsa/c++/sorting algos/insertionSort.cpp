#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
    arr = {11, 8, 15, 9, 4};
    
    for(int end = 0; end<arr.size()-1; end++){
        int index = end+1;
        while(index>0 && arr[index-1]>arr[end+1]) index--;
        if(index!=end+1){
            int temp = arr[end+1];
            for(int i = end+1; i>index; i--){
                arr[i] = arr[i-1];
            }
            arr[index] = temp;
        }
        for(auto n: arr) cout<<n<<" ";
        cout<<endl;
    }

    for(auto n: arr) cout<<n<<" ";
    return 0;
}