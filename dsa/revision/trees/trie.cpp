#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// TrieNode class represents a single node in the Trie
class TrieNode {
public:
    // Map to store children nodes, where key is the character and value is the TrieNode pointer
    map<char, TrieNode*> children;
    // Boolean flag to mark if this node represents the end of a word
    bool isEndOfWord;

    // Constructor to initialize a TrieNode
    TrieNode() : isEndOfWord(false) {}

    // Destructor to free memory allocated for children nodes
    ~TrieNode() {
        for (auto const& [key, val] : children) {
            delete val;
        }
    }
};

// Trie class represents the Trie data structure
class Trie {
private:
    TrieNode* root; // The root of the Trie

    // Private helper function to recursively delete a word
    // Returns the modified node. If a node is deleted, it returns nullptr.
    TrieNode* eraseHelper(TrieNode* curr, const string& word, int depth) {
        // If the current node is null, we can't proceed
        if (!curr) {
            return nullptr;
        }

        // Base Case: We have reached the end of the word to be deleted
        if (depth == word.length()) {
            // Unmark this node as the end of a word
            if (curr->isEndOfWord) {
                curr->isEndOfWord = false;
            }

            // If this node has no children (it's not a prefix for another word),
            // it's safe to delete.
            if (curr->children.empty()) {
                delete curr;
                curr = nullptr;
            }
            return curr;
        }

        // Recursive Step: Go deeper into the trie for the next character
        char ch = word[depth];
        
        // If the path for the word doesn't exist, we can't delete it.
        if (curr->children.find(ch) == curr->children.end()) {
            return curr;
        }

        // Recursively call for the child corresponding to the next character
        curr->children[ch] = eraseHelper(curr->children[ch], word, depth + 1);

        // If the recursive call resulted in the child node being deleted (returned nullptr),
        // remove the character from the current node's children map.
        if (curr->children[ch] == nullptr) {
            curr->children.erase(ch);
        }

        // After recursion, check if the current node can be deleted.
        // It can be deleted if it has no children left AND it's not the end of another word.
        if (curr->children.empty() && !curr->isEndOfWord) {
            delete curr;
            curr = nullptr;
        }

        return curr;
    }


public:
    // Constructor to initialize the Trie with an empty root node
    Trie() {
        root = new TrieNode();
    }

    // Destructor to free memory allocated for the entire Trie
    ~Trie() {
        delete root;
    }

    // Inserts a word into the Trie
    void insert(const string& word) {
        TrieNode* curr = root; // Start from the root
        for (char ch : word) {
            // If the character is not already a child, create a new node
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch]; // Move to the child node
        }
        curr->isEndOfWord = true; // Mark the end of the word
    }

    // Searches for a word in the Trie
    bool search(const string& word) {
        TrieNode* curr = root; // Start from the root
        for (char ch : word) {
            // If the character is not found, the word does not exist
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch]; // Move to the child node
        }
        // Return true only if the node exists and is marked as the end of a word
        return curr && curr->isEndOfWord;
    }

    // Public erase function to start the deletion process from the root
    void erase(const string& word) {
        if (word.empty()) return;
        root = eraseHelper(root, word, 0);
    }

    // Checks if there is any word in the Trie that starts with the given prefix
    bool startsWith(const string& prefix) {
        TrieNode* curr = root; // Start from the root
        for (char ch : prefix) {
            // If the character is not found, no word starts with this prefix
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch]; // Move to the child node
        }
        return true; // The prefix exists in the Trie
    }
};

int main() {
    Trie trie;

    // Test insert
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");

    // Test search
    cout << "--- Initial State ---" << endl;
    cout << "Searching for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl; // Expected: Found
    cout << "Searching for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;   // Expected: Found
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "True" : "False") << endl;     // Expected: True
    cout << endl;

    // Test erase: delete a word that is a prefix of another
    cout << "--- After Erasing 'app' ---" << endl;
    trie.erase("app");
    cout << "Searching for 'app': " << (trie.search("app") ? "Found" : "Not Found") << endl;   // Expected: Not Found
    cout << "Searching for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl; // Expected: Found
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "True" : "False") << endl;     // Expected: True
    cout << endl;

    // Test erase: delete a longer word
    cout << "--- After Erasing 'apple' ---" << endl;
    trie.erase("apple");
    cout << "Searching for 'apple': " << (trie.search("apple") ? "Found" : "Not Found") << endl; // Expected: Not Found
    cout << "Searching for 'apricot': " << (trie.search("apricot") ? "Found" : "Not Found") << endl; // Expected: Found
    cout << "Starts with 'app': " << (trie.startsWith("app") ? "True" : "False") << endl;     // Expected: True
    cout << endl;
    
    // Test erase: delete a word that is not a prefix of anything else
    cout << "--- After Erasing 'banana' ---" << endl;
    trie.erase("banana");
    cout << "Searching for 'banana': " << (trie.search("banana") ? "Found" : "Not Found") << endl; // Expected: Not Found
    cout << "Starts with 'ban': " << (trie.startsWith("ban") ? "True" : "False") << endl;     // Expected: False
    cout << endl;

    return 0;
}