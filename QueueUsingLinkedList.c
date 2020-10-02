#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void QueueTraversal()
{
    struct Node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int isEmpty(struct Node *f)
{
    if (f == NULL)
        return 1;
    else
        return 0;
}
int isFull(struct Node *n)
{
    if (n == NULL)
        return 1;
    else
        return 0;
}
void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (isFull(n))
        printf("Queue is full\n");

    else
    {
        n->data = val;
        n->next = NULL;
        if (front == NULL)
        {
            front = n;
            rear = n;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}
int dequeue()
{
    int val = -1;
    if (isEmpty(front))
    {
        printf("Queue Empty");
    }
    else
    {
        struct Node *ptr = front;
        front = front->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    QueueTraversal();
    printf("%d \n", dequeue());
    QueueTraversal();
    printf("%d \n", dequeue());
    QueueTraversal();
}