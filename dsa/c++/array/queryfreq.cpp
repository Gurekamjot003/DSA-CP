//if an element is present in array or not
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int N=1e5;
    vector<int> freq(N,0);   //freq having N elements, in which every element is initialized 0
    for(int i=0; i<n; i++){
        freq[v[i]]++;
    }
    cout<<"Enter queries: ";
    int q; cin>>q;
    while(q--){
        cout<<"Enter element to find its frequency: ";
        int queryelement;
        cin>>queryelement;
        cout<<"frequency: "<<freq[queryelement]<<endl;
    }
    return 0;
}