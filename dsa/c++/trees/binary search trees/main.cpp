#include<bits/stdc++.h>
#include "bst.cpp"
using namespace std;



int main(){
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    Node* root = NULL;
    for(int i = 0; i<n; i++) root = insert(root, arr[i]);
    display(root);
    cout<<endl;
    while(n!= -1){
        cin>>n;
        cout<<search(root, n)<<endl;       
    }
    return 0;
}