// Detect and remove loop in a linked list using Floyd's cycle detection algorithm

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
};

// Function to detect and remove a loop (if any)
void remove_loop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect loop using Floyd’s algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;  // Loop detected
    }

    // No loop found
    if (slow != fast) return;

    // Step 2: Find start of loop
    fast = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    // Now, `slow` (or `fast`) is at the start of the loop
    Node* loop_start = slow;

    // Step 3: Traverse to the last node in loop and remove the loop
    while (slow->next != loop_start) {
        slow = slow->next;
    }
    slow->next = nullptr;  // Loop removed
}

// Function to display the linked list
void display(Node* head) {
    Node* ptr = head;
    set<Node*> visited;

    while (ptr) {
        cout << ptr->val;
        if (visited.count(ptr)) break;
        cout << " -> ";
        visited.insert(ptr);
        ptr = ptr->next;
    }

    if (!visited.count(ptr)) cout << "NULL";
    cout << "\n\n";
}

int main() {
    // Create a linked list with a loop
    Node* head = new Node(1);
    Node* ptr = head;
    for (int i = 2; i <= 12; ++i) {
        ptr->next = new Node(i);
        ptr = ptr->next;
    }
    ptr->next = head->next->next->next;  // Create a loop at node 4

    cout << "List with loop:\n";
    display(head);  // Will stop if loop is detected using set
 
    remove_loop(head);

    cout << "List after removing loop:\n";
    display(head);  // Should end in NULL now

    return 0;
}
