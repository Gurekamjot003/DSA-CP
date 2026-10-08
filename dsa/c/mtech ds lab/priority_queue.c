#include <stdlib.h>
#include "dynamic_array.c"

typedef enum
{
    false = 0,
    true = 1
} bool;


typedef struct priority_queue
{
    vector* v;
} priority_queue;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sift_up(priority_queue *pq, int index)
{
    int* arr = pq->v->arr;
    while(index>0){
        int parent = (index-1)/2;
        if(arr[parent]<arr[index]){
            swap(&arr[parent], &arr[index]);
            index = parent;
        }
        else break;
    }
}

void sift_down(priority_queue *queue, int index)
{
    int*arr = queue->v->arr, size = queue->v->size;
    while(index<size){
        int max_idx = index, left = index*2+1, right = index*2 + 2;
        if(left<size && arr[left]>arr[max_idx]) max_idx = left;
        if(right<size && arr[right] > arr[max_idx]) max_idx = right;
        if(index == max_idx) return;
        swap(&arr[index], &arr[max_idx]);
        index = max_idx;
    }
}

void heapify(priority_queue *queue)
{
    int size = queue->v->size;
    int* arr = queue->v->arr;
    for(int i = (size-2)/2; i>=0; i--){
        sift_down(queue, i);
    }
}

priority_queue *init(int *a, int n)
{
    vector* v = init_vector(n, 0);
    for(int i = 0; i<n; i++){
        v->arr[i] = a[i];
    }
    priority_queue* ans = (priority_queue*) malloc(sizeof(priority_queue));
    ans->v = v;
    heapify(ans);
    return ans;
}

int top(priority_queue *queue)
{
    if(queue->v->size == 0) return -1;
    return queue->v->arr[0];
}

int pop(priority_queue *queue)
{
    int ans = top(queue);
    vector* v = queue->v;
    swap(&v->arr[0], &v->arr[v->size-1]);
    v->size--;
    sift_down(queue, 0);
    return ans;
}

bool increment_key(priority_queue *pq, int val, int index)
{
    pq->v->arr[index] = val;
    sift_up(pq, index);
    return true;
}

bool insert(priority_queue *pq, int val)
{
    push_back(pq->v, val);
    sift_up(pq, pq->v->size-1);
    return true;
}

bool delete(priority_queue *pq, int index)
{
    increment_key(pq, INT_MAX, index);
    pop(pq);
}

void free_pq(priority_queue *pq)
{
   free_vector(pq->v);
   free(pq);
}

priority_queue *meld(priority_queue *pq1, priority_queue *pq2)
{
    for(int i = 0; i<pq2->v->size; i++){
        push_back(pq1->v, pq2->v->arr[i]);
    }
    heapify(pq1);
    free_pq(pq2);
    return pq1;
}


int main(void)
{
    return 0;
}
