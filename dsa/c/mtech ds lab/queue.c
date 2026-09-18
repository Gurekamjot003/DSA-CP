#include "queue.h" 

int main()
{
    Queue *q = init(5);

    push(q, 5);
    push(q, 6);
    printf("%d\n", get_front(q));
    pop(q);
    pop(q);
    if (get_front(q) == -1)
        printf("Q is empty\n");
    else
        printf("%d\n", get_front(q));

    push(q, 7);
    free_queue(q);

    return 0;
}