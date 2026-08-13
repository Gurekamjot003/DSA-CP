#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include "binaryTrees.cpp"
using namespace std;

Node* buildTree() {
    int val;
    cout << "Enter node value (-1 for NULL): ";
    cin >> val;
    if (val == -1) return nullptr;

    Node* n = new Node(val);
    cout << "Enter left child of " << val << ": ";
    n->left = buildTree();
    cout << "Enter right child of " << val << ": ";
    n->right = buildTree();

    return n;
}

int main() {
    cout << "Build the binary tree:\n";
    Node* root = buildTree();  // Create the tree using the member function

    cout << Node::leetcodeDisplay(root) << endl;  // Display in LeetCode format

    return 0;
}
