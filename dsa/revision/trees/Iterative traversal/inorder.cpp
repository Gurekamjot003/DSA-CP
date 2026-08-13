#include<bits/stdc++.h>
#include "../Node.hpp"
using namespace std;

vector<int> inorder(Node* root){
    stack<Node*> st;
    vector<int> ans;
    Node* ptr = root;

    // we have to always push all the nodes from cur node going to left child
    while(ptr){
        st.push(ptr);
        ptr = ptr->left;
    }

    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        // process cur node
        ans.push_back(node->val);

        // push all left children of right
        Node* ptr = node->right;
        while(ptr){
            st.push(ptr);
            ptr = ptr->left;
        }
    }
    return ans;
}

int main(){
    Node* root = example_tree();

    vector<int> in= inorder(root);

    for(auto& n: in) cout<<n<< " ";
}