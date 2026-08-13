#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    // Value stored in the node
    int val, height;
    // Pointers to left and right children
    Node *left, *right;
    Node(int value){
        val = value;
        height = 1;
        left = right = NULL;
    }
};

int get_height(Node* root){
    // Returns the height of the node, 0 if null
    if(!root) return 0;
    return root->height;
}

int get_balance(Node* root){
    // Calculates the balance factor (height of left subtree - height of right subtree)
    return get_height(root->left) - get_height(root->right);
}

// Performs a left rotation on the given node
Node* left_rotation(Node* root){
    Node* child = root->right;
    Node* child_left = child->left;

    child->left = root;
    root->right = child_left;

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    child->height = 1 + max(get_height(child->left), get_height(child->right));
    
    return child;
}

// Performs a right rotation on the given node
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
        // Right subtree is heavier
        int right_balance = get_balance(root->right);
        if(right_balance > 0) root->right = right_rotation(root->right);
        root = left_rotation(root);
    }
    // Return the (potentially new) root of the subtree
    return root;
}

// Performs a preorder traversal of the AVL tree
void preorder(Node* root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
// Performs an inorder traversal of the AVL tree
void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;
    // Values to insert into the AVL tree
    vector<int> insertions = {10, 20, 30, 50, 70, 5, 100, 95};
    cout << "Inserting elements: ";
    for(auto& n: insertions){
        cout << n << " ";
        root = insert(root, n);
    }
    cout << endl << endl;

    cout << "Preorder traversal after insertions: ";
    preorder(root);
    cout<<endl;
    cout << "Inorder traversal after insertions: ";
    inorder(root);
    cout << endl << endl;

    return 0;
}