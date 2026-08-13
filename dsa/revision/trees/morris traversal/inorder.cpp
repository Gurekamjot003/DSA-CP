#include<bits/stdc++.h>
#include "../Node.hpp"
using namespace std;

vector<int> inorder(Node* root){
    vector<int> ans;
    while(root){
        Node* ptr = root->left;
        if(ptr){
            //check for right most child of left
            while(ptr->right && ptr->right != root){
                ptr = ptr->right;
            }
            // if nullptr is reached then connect to root
            if(!ptr->right){
                ptr->right = root;
                root = root->left;
            }
            // otherwise it is root which is connected
            // this means that this node is already visited we remove the connection and carry on with further processing
            else{
                ptr->right = nullptr;
                ans.push_back(root->val);
                root = root->right;
            }
        }
        // if left child doesn't exists then we have to process cur node and go to right
        else{
            ans.push_back(root->val);
            root = root->right;
        }
    
    }

    return ans;
}

int main(){
    Node* root = example_tree();

    vector<int> ans = inorder(root);
    for(auto& n: ans) cout<<n<<" ";

}