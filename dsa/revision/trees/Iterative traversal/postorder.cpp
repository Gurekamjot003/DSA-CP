#include<bits/stdc++.h>
#include "../Node.hpp"
using namespace std;

vector<int> postorder(Node* root){
    stack<Node*> st;
    st.push(root);
    vector<int> ans;
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        ans.push_back(node->val);
        if(node->left) st.push(node->left);
        if(node->right) st.push(node->right);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    Node* root = example_tree();

    vector<int> post= postorder(root);

    for(auto& n: post) cout<<n<< " ";
}