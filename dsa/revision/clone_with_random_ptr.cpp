#include <bits/stdc++.h>
using namespace std;

// Node class with next and random pointers
class Node {
public:
    int val;
    Node* next, *random;

    Node(int val): val(val), next(nullptr), random(nullptr) {}
};

// Function to clone a linked list with next and random pointers
Node* copyRandomList(Node* head) {
    Node* current = head;

    // Step 1: Create new copy nodes and insert them right next to original nodes
    while(current) {
        Node* copyNode = new Node(current->val);
        copyNode->next = current->next;
        current->next = copyNode;
        current = copyNode->next;
    }

    // Step 2: Set random pointers of copy nodes
    current = head;
    while(current) {
        Node* copyNode = current->next;
        if(current->random) {
            copyNode->random = current->random->next;
        }
        current = copyNode->next;
    }

    // Step 3: Separate the two interleaved lists into original and copied list
    Node* dummyCopyHead = new Node(0);  // Dummy node for copied list
    Node* copyCurrent = dummyCopyHead;

    Node* dummyOriginalHead = new Node(0);  // Dummy node for original list (not needed, just maintaining symmetry)
    Node* originalCurrent = dummyOriginalHead;

    current = head;
    bool addToCopyList = false;

    while(current) {
        if(addToCopyList) {
            copyCurrent->next = current;
            copyCurrent = copyCurrent->next;
        } else {
            originalCurrent->next = current;
            originalCurrent = originalCurrent->next;
        }
        current = current->next;
        addToCopyList = !addToCopyList;
    }

    dummyOriginalHead->next = nullptr; // Terminate original list
    return dummyCopyHead->next;        // Return head of copied list
}

// Helper function to display next and random pointers
void display(Node* head) {
    cout << "Next pointers:" << endl;
    Node* current = head;
    while(current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL\n";

    cout << "Random pointers:" << endl;
    current = head;
    while(current) {
        cout << current->val << " -> ";
        if(current->random)
            cout << current->random->val << endl;
        else
            cout << "NULL" << endl;
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    map<int ,Node*> indexToNode;
    indexToNode[0] = nullptr;
    indexToNode[1] = head;
    Node* current = head;

    // Creating linked list with values 1 to 10
    for(int i = 2; i <= 10; i++) {
        current->next = new Node(i);
        indexToNode[i] = current->next;
        current = current->next;
    }

    // Assign random pointers randomly using map
    current = head;
    while(current) {
        int randIndex = rand() % 11;
        current->random = indexToNode[randIndex];
        current = current->next;
    }

    display(head);  // Show original list

    Node* clone = copyRandomList(head);  // Create deep copy

    display(clone);  // Show cloned list
}
