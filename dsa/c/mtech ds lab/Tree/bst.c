#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "../dynamic_array.c"

Node* init_bst(int* arr, int sz){
    if(sz<1) return NULL;
    int mid = (sz-1)/2;
    Node* ans = arr[mid];
    ans->left = init_bst(arr, mid);
    if(ans->left) ans->left->parent = ans;
    ans->right = init_bst(&arr[mid+1], sz-mid-1);
    if(ans->right) ans->right->parent = ans;
    return ans;
}

Node *insert(Node *root, int val)
{
    if (!root)
        return init_node(val);
    if (root->val > val){
        root->left = insert(root->left, val);
        root->left->parent = root;
    }
    else{
        root->right = insert(root->right, val);
        root->right->parent = root;
    }
    return root;
}

Node *erase(Node *root, int val)
{
    if (!root)
        return NULL;
    if (root->val == val)
    {
        Node *ans = NULL;
        if (!root->left)
        {
            ans = root->right;
            if(ans) ans->parent = root->parent;
            free(root);
        }
        else if (!root->right)
        {
            ans = root->left;
            if(ans) ans->parent = root->parent;
            free(root);
        }
        else
        {
            // printf("Yes");
            Node *ptr = root->left;
            while (ptr->right)
            {
                ptr = ptr->right;
            }
            root->val = ptr->val;
            root->left = erase(root->left, ptr->val);
            ans = root;
        }
        return ans;
    }
    else if (root->val < val)
        root->right = erase(root->right, val);
    else
        root->left = erase(root->left, val);
    return root;
}

Node* search(Node* root, int val){
    if(!root) return NULL;
    if(root->val == val) return root;
    if(root->val>val) return search(root->left, val);
    return search(root->right, val);
}

Node* inorder_predecessor(Node* cur){
    if(!cur) return NULL;
    if(cur->left){ // then it will be present on right spine of left subtree
        Node* ptr = cur->left;
        while(ptr->right) ptr = ptr->right;
        return ptr;
    }
    Node* ptr = cur;
    while(ptr->parent && ptr->parent->left == ptr){
        ptr = ptr->parent;
    }
    if(!ptr->parent) return NULL;
    return ptr->parent;
}

Node* inorder_successor(Node* cur){
    if(!cur) return NULL;
    if(cur->right){ // then it will be present on left spine of right subtree
        Node* ptr = cur->right;
        while(ptr->left) ptr = ptr->left;
        return ptr;
    }
    Node* ptr = cur;
    while(ptr->parent && ptr->parent->right == ptr){
        ptr = ptr->parent;
    }
    if(!ptr->parent) return NULL;
    return ptr->parent;
}

Node* erase_sir_method(Node* root, int val){
    Node* to_delete = search(root, val);
    Node* replacement = NULL;
    if(to_delete->left){
        replacement = inorder_predecessor(to_delete);
    }
    else if(to_delete->right){
        replacement = inorder_successor(to_delete);
    }
    else{ // leaf node
        if(!to_delete->parent){ // root node is leaf node
            free(to_delete);
            return NULL;
        }

        Node* parent = to_delete->parent;
        if(to_delete->val <= parent->val) parent->left = NULL;
        else parent->right = NULL;
        free(to_delete);
        return root;
    }
    int replacement_val = replacement->val;
    Node* parent = replacement->parent; // it can be proven that parent of replacement always exists
    if(replacement->val <= parent->val){
        parent->left = erase_sir_method(parent->left, replacement->val);
        if(parent->left) parent->left->parent = parent;
    }
    else{
        parent->right = erase_sir_method(parent->right, replacement->val);
        if(parent->right) parent->right->parent = parent;
    }
    to_delete->val = replacement_val;
    return root;
}

Node* max_node(Node* root){
    if(!root) return NULL;
    Node* ptr = root;
    while(ptr->right){
        ptr = ptr->right;
    }
    return ptr;
}

int max(Node* root){
    Node* req = max_node(root)->val;
    if(req) return req->val;
    return INT_MIN;
}

Node* min_node(Node* root){
    if(!root) return NULL;
    Node* ptr = root;
    while(ptr->left){
        ptr = ptr->left;
    }
    return ptr;
}

int min(Node* root){
    Node* req = min_node(root)->val;
    if(req) return req->val;
    return INT_MAX;
}

void get_all_helper(Node* root, vector* ele){
    if(!root) return;
    get_all_helper(root->left, ele);
    push_back(ele, root->val);
    get_all_helper(root->right, ele);
}

vector* get_all_elements(Node* root){
    vector* ans = init_vector(0, 0);
    get_all_helper(root, ans);
    return ans;
}

Node* join(Node* root1, Node* root2){
    if(!root1) return root2;
    if(!root2) return root1;
    Node* min1 = min_node(root1), 
        * max1 = max_node(root1),
        * min2 = min_node(root2),
        * max2 = max_node(root2);

    if(max1->val < min2->val){
        min2->left = root1;
        return root2;
    }
    if(max2->val < min1->val){
        min1->left = root2;
        return root1;
    }
    
    // method by sir
    
    /*
    if(max2->val < min1->val){
        swap(root1, root2);
    }
    if(max1->val < min2->val){
        Node* ans = init_node(max1->val);
        root1 = erase(root1, max1->val);
        ans->left = root1;
        ans->right = root2;
        return ans;
    }
    */


    // This case is in which we have to do naively in O(n+m)
    vector* ele1 = get_all_elements(root1), *ele2 = get_all_elements(root2);
    free_tree(root1); free_tree(root2);
    for(int i = 0; i<ele2->size; i++){
        push_back(ele1, ele2->arr[i]);
    }
    
    Node* ans = init_bst(ele1->arr, ele1->size);
    free_vector(ele1);
    free_vector(ele2);
    return ans;
}

Node** split(Node* root, int val){ // split tree into two trees => one having all values <= val & other having > val
    Node* small = init_node(0), *large = init_node(0); // dummy nodes
    Node* small_ptr = small, *large_ptr = large;
    Node* tree_ptr = root;

    while(tree_ptr){
        if(tree_ptr->val<=val){
            small_ptr->right = tree_ptr;
            tree_ptr->parent = small_ptr;
            small_ptr = small_ptr->right;
            tree_ptr = tree_ptr->right;
            small_ptr->right = NULL;
            if(tree_ptr) tree_ptr->parent = NULL;
        }
        else{
            large_ptr->left = tree_ptr;
            tree_ptr->parent = large_ptr;
            large_ptr = large_ptr->left;
            tree_ptr = tree_ptr->left;
            large_ptr->left = NULL;
            if(tree_ptr) tree_ptr->parent = NULL;
        }
    }

    Node* ans[] = {small->right, large->left};
    if(small->right) small->right->parent = NULL;
    if(large->left) large->left->parent = NULL;
    free(small);
    free(large);
    return ans;
}

int main()
{
    int arr[] = {6, 5, 34, 1, 2, 3};
    Node *root = NULL;
    print(root);
    for (int i = 0; i < 6; i++)
    {
        root = insert(root, arr[i]);
        print(root);
    }

    int arr_del[] = {6, 1, 2};
    for (int i = 0; i < 3; i++)
    {
        root = erase(root, arr_del[i]);
        print(root);
    }

    return 0;
}