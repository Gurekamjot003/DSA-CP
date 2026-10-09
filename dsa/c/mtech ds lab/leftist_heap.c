#include <stdlib.h>

typedef enum
{
    false = 0,
    true = 1
} bool;

typedef struct Node
{
    int val;
    struct Node *left, *right, *parent;
    int s;
} Node;

Node *init_node(int val)
{
    Node *ans = (Node *)malloc(sizeof(Node));
    ans->val = val;
    ans->left = ans->right = ans->parent = nil;
    ans->s = 1;
    return ans;
}

typedef struct priority_queue
{
    Node* root;
    int size;
} priority_queue;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_children(Node* node){
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

Node* nil;

priority_queue *init_null_pq()
{
    priority_queue* ans = (priority_queue*)malloc(sizeof(priority_queue));
    ans->root = nil;
    ans->size = ans->root->s = 0;
}

Node* merge_trees(Node* root1, Node* root2){
    if(root1 == nil) return root2;
    if(root2 == nil) return root1;
    Node* ans;
    if(root1->val > root2->val){
        ans = root1;
        root1 = root1->right;
    }
    else{
        ans = root2;
        root2 = root2->right;
    }
    ans->right = merge_trees(root1, root2);
    if(ans->right != nil) ans->right->parent = ans;
    if(ans->left->s > ans->right->s) swap_children(ans);
    ans->s = ans->right->s+1;
    return ans;
}

priority_queue *meld(priority_queue *pq1, priority_queue *pq2)
{
    priority_queue* ans = init();
    Node* root = merge_trees(pq1->root, pq2->root);
    ans->root = root;
    ans->size = pq1->size + pq2->size;
    free(pq1);
    free(pq2);
    return ans;
}

priority_queue* init_single_ele_pq(int val){
    priority_queue* ans = init();
    ans->root = init_node(val);
    ans->size = 1;
    return ans;
}

priority_queue* init_pq(int* arr, int n){  // using merge sort logic (divide & conquer), sir used queue logic
    if(n == 1) {
        return init_single_ele_pq(arr[0]);
    }
    int mid = n/2;
    priority_queue* left = init_pq_from_arr(arr, mid), *right = init_pq_from_arr(&arr[mid], n-mid);
    priority_queue* ans = meld(left, right);
    return ans;
}

priority_queue* insert(priority_queue *pq, int val)
{
    return meld(pq, init_single_ele_pq(val));
}

int max(priority_queue *pq)
{
    if(pq->size == 0) return -1;
    return pq->root->val;
}

int extract_max(priority_queue *pq)
{
    int ans = max(pq);
    pq->root = merge_trees(pq->root->left, pq->root->right);
    free(pq->root);
    pq->size--;
    return ans;
}

bool delete(priority_queue *pq, Node** to_delete)
{
    Node* parent = (*to_delete)->parent;
    *to_delete = merge_trees((*to_delete)->left, (*to_delete)->right);
    (*to_delete)->parent = parent;
    return true;
}


bool increment_key(priority_queue *pq, int val, Node* node)
{
    delete(pq, node);
    pq = meld(pq, init_single_ele_pq(val));
    return true;
}


void free_node(Node* node){
    if(node == nil) return;
    Node* left = node->left, *right = node->right;
    free(node);
    free_node(left);
    free_node(right);
}

void free_pq(priority_queue *pq)
{
    free_node(pq->root);
    free(nil);
    free(pq);
}



int main(void)
{
    return 0;
}
