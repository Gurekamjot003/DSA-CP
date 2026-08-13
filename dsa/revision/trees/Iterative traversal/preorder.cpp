#include<bits/stdc++.h>
#include "../Node.hpp"
using namespace std;

vector<int> preorder(Node* root){
    stack<Node*> st;
    st.push(root);
    vector<int> ans;
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        // the node which is processed pushes its children at runtime
        ans.push_back(node->val);

        //push right and then left LIFO
        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    return ans;
}

int main(){
    Node* root = example_tree();

    vector<int> pre = preorder(root);

    for(auto& n: pre) cout<<n<< " ";
}