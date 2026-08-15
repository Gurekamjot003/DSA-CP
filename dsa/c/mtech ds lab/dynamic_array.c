#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int capacity, size;
    int *arr;
} vector;

int get_greater_pow_2(int n)
{
    if (n <= 0)
        return 4;
    int cap = 1;
    while (cap < n)
    {
        cap <<= 1;
    }
    return cap;
}

vector *init_vector(int sz, int value)
{
    vector *v = (vector *)malloc(sizeof(vector));

    v->capacity = get_greater_pow_2(sz);
    v->arr = (int *)malloc(sizeof(int) * v->capacity);
    v->size = sz;

    for (int i = 0; i < sz; i++)
    {
        v->arr[i] = value;
    }
    return v;
};

int push_back(vector *v, int val)
{
    if (v == NULL)
        return 0;
    if (v->size == v->capacity)
    {
        int *new_arr = (int *)realloc(v->arr, sizeof(int) * v->capacity * 2);
        if (new_arr == NULL)
            return 0;
        v->arr = new_arr;
        v->capacity *= 2;
    }
    v->arr[v->size++] = val;
    return 1;
}

int access_element(vector *v, int i)
{
    if (i >= v->size || i < 0)
    {
        printf("Segmentation fault!\n%d is out of scope", i);
        return INT_MIN;
    }
    return v->arr[i];
}

int pop_back(vector *v)
{
    if (v == NULL || v->size == 0)
        return 0;
    if (--v->size < v->capacity / 4)
    {
        int *new_arr = (int *)realloc(v->arr, sizeof(int) * v->capacity / 2);
        if (new_arr == NULL)
            return 0;
        v->arr = new_arr;
        v->capacity /= 2;
    }
    return 1;
}

void free_vector(vector *v)
{
    if (v)
    {
        free(v->arr);
        free(v);
    }
}

int main()
{
    vector *v = init_vector(0, 0);
    for (int i = 1; i < 100; i++)
        push_back(v, i);
    for (int i = 0; i < v->size; i++)
    {
        printf("%d ", access_element(v, i));
    }
    printf("\n");
    for (int i = 0; i < 80; i++)
    {
        pop_back(v);
    }
    printf("Capacity = %d\n", v->capacity);
    for (int i = 0; i < v->size; i++)
    {
        printf("%d ", access_element(v, i));
    }
    free_vector(v);
    return 0;
}