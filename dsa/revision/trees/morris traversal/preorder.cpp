#include<bits/stdc++.h>
#include "../Node.hpp"
using namespace std;

vector<int> preorder(Node* root){
    vector<int> ans;
    // Loop until the current root becomes null
    while(root){
        // Initialize ptr to the left child of the current root
        Node* ptr = root->left;
        // If a left child exists
        if(ptr){
            // Find the rightmost node in the left subtree (predecessor)
            // This loop finds the inorder predecessor of the current root
            while(ptr->right && ptr->right != root){
                ptr = ptr->right;
            }
            // If the right pointer of the predecessor is null, it means we haven't visited this subtree yet
            if(!ptr->right){
                // Create a thread from the predecessor back to the current root
                ptr->right = root;
                // Add the current node's value to the result (preorder: process root first)
                ans.push_back(root->val);
                // Move to the left child
                root = root->left;
            }
            // If the right pointer of the predecessor points to the current root, it means we have already visited this subtree
            else{
                // Break the thread (restore the tree structure)
                ptr->right = nullptr;
                // Move to the right child (after processing the left subtree)
                root = root->right;
            }
        }
        // If left child does not exist
        else{
            // Add the current node's value to the result
            ans.push_back(root->val);
            // Move to the right child
            root = root->right;
        }
    
    }

    return ans;
}

int main(){
    Node* root = example_tree();

    vector<int> ans = preorder(root);
    for(auto& n: ans) cout<<n<<" ";

}