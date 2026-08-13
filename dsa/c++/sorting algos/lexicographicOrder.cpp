// given an array names of fruits you are supposed to sort it in lexicographic order using selection sort

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    vector<string> arr;
    arr = {"papaya", "lime", "watermellon", "mango", "kiwi"};
    for(int i = 0; i< arr.size(); i++){
        string shortest = arr[i];
        int ind = i;
        for(int j = i+1; j<arr.size(); j++){
            for(int k = 0; k<shortest.size() && k<arr[j].size(); k++){
                if(shortest[k] > arr[j][k]){
                    shortest = arr[j];
                    ind = j;
                    break;
                }
                else if (shortest[k] < arr[j][k])
                {
                    break;
                }
                
            }
        }
        if(ind != i) swap(arr[i], arr[ind]);
        for(auto n: arr) cout<<n<<" ";
        cout<<endl;
    }
    for(auto n: arr) cout<<n<<" ";
    return 0;
}