#include<stdio.h>
#include<stdlib.h>

typedef enum{
    FALSE = 0, TRUE = 1
} boolean;

typedef struct{
    int val;
    Node* next;
} Node;

Node* init_node(int val, Node* next){
    Node* ans = (Node*) malloc(sizeof(Node));
    ans->val = val;
    if(!next) ans->next = ans;
    else ans->next = next;
}

Node* search(Node* head, int val){
    // case 1 val at head
    if(head->val == val) return head;
    // case 2 val present but not at head
    Node* ptr = head->next;
    while(ptr != head && ptr->val != val) ptr = ptr->next;
    if(ptr->val == val) return ptr;

    // case 3 val not present
    return NULL;
}

Node* insert(Node* head, int val, int target){
    Node* prev = search(head, target);
    if(prev){
        Node* cur = init_node(val, prev->next);
        prev->next = cur;
    }
    return head;
}

Node* delete(Node* head, int target){
    Node* to_delete = search(head, target);
    // case 1 node not found
    if(!to_delete) return head;
    // case 2 node is head itself
    if(to_delete == head){
        if(head->next != head){
            
            Node* ans = head->next;
            free(head);
            return ans;
        }
        else{
            free(head);
            return NULL;
        }
    }
    // case 3 node is anywhere but not head
    Node* ptr = head;
    while(ptr && ptr->next != to_delete) ptr = ptr->next;
    ptr->next = ptr->next->next;
    free(to_delete);
    return head;
}

Node* delete_all(Node* head){
    if(!head) return NULL;
    Node* ptr = head->next;
    while(ptr && ptr != head){
        Node* next = ptr->next;
        free(ptr);
        ptr = next;
    }
    free(head);
    return NULL;
}

int main(){

}