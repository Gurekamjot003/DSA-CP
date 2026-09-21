#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

Node *init_node(int val)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->val = val;
    ans->left = ans->right = ans->parent = NULL;
    return ans;
}

Node *insert(Node *root, int val)
{
    if (!root)
        return init_node(val);
    if (root->val > val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
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
            free(root);
        }
        else if (!root->right)
        {
            ans = root->left;
            free(root);
        }
        else
        {
            printf("Yes");
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
    if(cur->right){ // then it will be present on right spine of left subtree
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
    if(!to_delete) return root; // does not exist 
    if(!to_delete->left && !to_delete->right){ // leaf node
        if(!to_delete->parent){  // parent does not exist
        }   
        else if(to_delete->parent->left == to_delete) to_delete->parent->left = NULL; // cut parent connection
        else to_delete->parent->right = NULL;
        free(to_delete);

    }
    Node* replacement = inorder_predecessor(to_delete);
    if(!replacement) replacement = inorder_successor(to_delete);
    if(!replacement){ // this means root is the only chile dot delete
        free(to_delete);
        return NULL;
    }
    to_delete->val = replacement->val;

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