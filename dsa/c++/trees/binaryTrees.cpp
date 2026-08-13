#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    // Constructor to initialize node with a value
    Node(int value) : val(value), left(nullptr), right(nullptr) {}

    // Function to display the tree in LeetCode's format
    static string leetcodeDisplay(Node* root) {
        cout << "\nLeetCode-style output of the tree:\n";
        if (!root) return "[]";
        
        vector<string> result;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            if (node) {
                result.push_back(to_string(node->val));
                q.push(node->left);
                q.push(node->right);
            } else {
                result.push_back("null");
            }
        }

        // Remove trailing "null" elements
        while (result.back() == "null") {
            result.pop_back();
        }

        // Format the output in LeetCode's style
        string output = "[";
        for (int i = 0; i < result.size(); ++i) {
            output += result[i];
            if (i < result.size() - 1) output += ",";
        }
        output += "]";
        
        return output;
    }
};
