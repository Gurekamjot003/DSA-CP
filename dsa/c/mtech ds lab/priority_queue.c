#include <stdlib.h>

typedef enum
{
    false = 0,
    true = 1
} bool;

#define MIN_INT (-2147483647 - 1)
#define MAX_INT 2147483647

typedef struct pq
{
    int *a;
    int n;
    int capacity;
} pq;

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static void sift_up(pq *queue, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (queue->a[parent] >= queue->a[index])
            break;
        swap(&queue->a[parent], &queue->a[index]);
        index = parent;
    }
}

static void sift_down(pq *queue, int index)
{
    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;

        if (left < queue->n && queue->a[left] > queue->a[largest])
            largest = left;
        if (right < queue->n && queue->a[right] > queue->a[largest])
            largest = right;
        if (largest == index)
            return;

        swap(&queue->a[index], &queue->a[largest]);
        index = largest;
    }
}

static void heapify(pq *queue)
{
    for (int index = queue->n / 2 - 1; index >= 0; index--)
        sift_down(queue, index);
}

pq *init(int *a, int n)
{
    if (n < 0 || (n > 0 && !a))
        return NULL;

    pq *queue = malloc(sizeof(pq));
    if (!queue)
        return NULL;

    queue->capacity = n > 4 ? n : 4;
    queue->n = n;
    queue->a = malloc((size_t)queue->capacity * sizeof(int));
    if (!queue->a)
    {
        free(queue);
        return NULL;
    }

    for (int index = 0; index < n; index++)
        queue->a[index] = a[index];
    heapify(queue);
    return queue;
}

int top(pq *queue)
{
    if (!queue || queue->n == 0)
        return MIN_INT;
    return queue->a[0];
}

int pop(pq *queue)
{
    if (!queue || queue->n == 0)
        return MIN_INT;

    int result = queue->a[0];
    queue->a[0] = queue->a[--queue->n];
    if (queue->n > 0)
        sift_down(queue, 0);
    return result;
}

bool increment_key(pq *queue, int val, int k)
{
    if (!queue || k < 0)
        return false;

    for (int index = 0; index < queue->n; index++)
    {
        if (queue->a[index] == val)
        {
            if (k > MAX_INT - queue->a[index])
                return false;
            queue->a[index] += k;
            sift_up(queue, index);
            return true;
        }
    }
    return false;
}

bool insert(pq *queue, int x)
{
    if (!queue)
        return false;

    if (queue->n == queue->capacity)
    {
        int new_capacity = queue->capacity * 2;
        int *new_array = realloc(queue->a, (size_t)new_capacity * sizeof(int));
        if (!new_array)
            return false;
        queue->a = new_array;
        queue->capacity = new_capacity;
    }

    queue->a[queue->n] = x;
    queue->n++;
    sift_up(queue, queue->n - 1);
    return true;
}

bool delete(pq *queue, int x)
{
    if (!queue)
        return false;

    for (int index = 0; index < queue->n; index++)
    {
        if (queue->a[index] == x)
        {
            queue->a[index] = queue->a[--queue->n];
            if (index < queue->n)
            {
                if (index > 0 && queue->a[index] > queue->a[(index - 1) / 2])
                    sift_up(queue, index);
                else
                    sift_down(queue, index);
            }
            return true;
        }
    }
    return false;
}

pq *meld(pq *queue1, pq *queue2)
{
    if (!queue1 || !queue2)
        return NULL;

    pq *result = malloc(sizeof(pq));
    if (!result)
        return NULL;

    result->n = queue1->n + queue2->n;
    result->capacity = result->n > 4 ? result->n : 4;
    result->a = malloc((size_t)result->capacity * sizeof(int));
    if (!result->a)
    {
        free(result);
        return NULL;
    }

    for (int index = 0; index < queue1->n; index++)
        result->a[index] = queue1->a[index];
    for (int index = 0; index < queue2->n; index++)
        result->a[queue1->n + index] = queue2->a[index];
    heapify(result);
    return result;
}

void free_pq(pq *queue)
{
    if (queue)
    {
        free(queue->a);
        free(queue);
    }
}

int main(void)
{
    return 0;
}
