#include<bits/stdc++.h>
#include "../Node.hpp"
using namespace std;

vector<int> postorder(Node* root){
    vector<int> ans;
    while(root){
        Node* ptr = root->right;
        // If right child exists
        if(ptr){
            // Find the leftmost node in the right subtree
            // This is the inorder predecessor in the reversed inorder traversal
            while(ptr->left && ptr->left != root){
                ptr = ptr->left;
            }
            // If the leftmost node's left pointer is null, it means we haven't visited this subtree yet
            if(!ptr->left){
                // Create a thread from the leftmost node back to the current root
                ptr->left = root;
                // Add the current node's value to the result (for postorder, we add it before moving right)
                ans.push_back(root->val);
                // Move to the right child
                root = root->right;
            }
            // If the leftmost node's left pointer points to the current root, it means we have already visited this subtree
            else{
                // Break the thread
                ptr->left = nullptr;
                // Move to the left child (this is where the actual traversal happens after processing the right subtree)
                root = root->left;
            }
        }
        // If right child does not exist
        else{
            // Add the current node's value to the result
            ans.push_back(root->val);
            // Move to the left child
            root = root->left;
        }
    }
    // For postorder, the Morris traversal naturally gives a reversed postorder, so reverse the result
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    Node* root = example_tree();

    vector<int> ans = postorder(root);
    for(auto& n: ans) cout<<n<<" ";
}