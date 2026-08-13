#pragma once

class Node{
public:
    int val;
    Node* left, *right;

    Node(int val): val(val), left(nullptr), right(nullptr){}
};

Node* example_tree(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    return root;
}