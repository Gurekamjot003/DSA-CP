#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val, height;
    Node *left, *right;
    Node(int value){
        val = value;
        height = 1;
        left = right = NULL;
    }
};

int get_height(Node* root){
    if(!root) return 0;
    return root->height;
}

int get_balance(Node* root){
    return get_height(root->left) - get_height(root->right);
}

Node* left_rotation(Node* root){
    Node* child = root->right;
    Node* child_left = child->left;

    child->left = root;
    root->right = child_left;

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    child->height = 1 + max(get_height(child->left), get_height(child->right));
    
    return child;
}

Node* right_rotation(Node* root){
    Node* child = root->left;
    Node* child_right = child->right;
    
    child->right = root;
    root->left = child_right;
    
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    child->height = 1 + max(get_height(child->left), get_height(child->right));

    return child;    
}

Node* insert(Node* root, int n){
    if(!root) return new Node(n);

    if(n< root->val) root->left = insert(root->left, n);
    else if( n> root->val) root->right = insert(root->right, n);
    else return root;

    root->height = 1 + max(get_height(root->left), get_height(root->right));

    int balance = get_balance(root);

    if(balance>1){
        // LL case
        if(n < root->left->val){
            root = right_rotation(root);
        }
        // LR case
        else{
            root->left = left_rotation(root->left);
            root = right_rotation(root);
        }
    }
    else if(balance < (-1)){
        // RR case
        if(n>root->right->val){
            root = left_rotation(root);
        }
        // RL case
        else{
            root->right = right_rotation(root->right);
            root = left_rotation(root);
        }
    }
    // balanced 
    
    return root;

}

Node* del(Node* root, int n){
    if(!root) return NULL;
    if(n>root->val) root->right = del(root->right, n);
    else if(n<root->val) root->left = del(root->left, n);
    else{
        //both children
        if(root->left && root->right){
            Node* left_max = root->left;
            while(left_max->right){
                left_max = left_max->right;
            }
            root->val = left_max->val;
            root->left = del(root->left, left_max->val);
        }   
        //single child
        else if(root->left or root->right){
            Node* child = root->left;
            if(!child) child = root->right;
            delete root;
            return child;
        }
        //Leaf node
        else{
            delete root;
            return NULL;
        }

    }

    root->height = 1 + max(get_height(root->left), get_height(root->right));

    int balance = get_balance(root);
    //left side
    if(balance>1){
        int left_balance = get_balance(root->left);
        if(left_balance<0) root->left = left_rotation(root->left);
        root = right_rotation(root);
    }
    //right side
    else if(balance < (-1)){
        int right_balance = get_balance(root->right);
        if(right_balance > 0) root->right = right_rotation(root->right);
        root = left_rotation(root);
    }
    return root;
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    vector<int> insertions = {10, 20, 30, 50, 70, 5, 100, 95};
    for(auto& n: insertions){
        root = insert(root, n);
    }
    preorder(root);
    cout<<endl;
    inorder(root);
    return 0;
}