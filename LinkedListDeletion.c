#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void LinkdeListTraversal(struct Node *ptr)
{
    // printf("Data in linked list is: \n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
// Case 1:
struct Node *DeleteBeginning(struct Node *head)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// Case 2:
struct Node *DeleteInBetween(struct Node *head, int index)
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);

    return head;
}
// Case 3:
struct Node *DeleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = p->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);

    return head;
}

struct Node *DeleteKey(struct Node *head, int key)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != key && q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    if (q->data == key)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 20;
    head->next = second;
    second->data = 30;
    second->next = third;
    third->data = 40;
    third->next = fourth;
    fourth->data = 50;
    fourth->next = fifth;
    fifth->data = 60;
    fifth->next = NULL;

    printf("Original List: \n");
    LinkdeListTraversal(head);

    // head = DeleteBeginning(head);
    // printf("\n");
    // printf("After Deletion from beginning: \n");
    // LinkdeListTraversal(head);

    // head = DeleteInBetween(head, 2);
    // printf("\n");
    // printf("After Deletion from given Index: \n");
    // LinkdeListTraversal(head);

    // head = DeleteAtEnd(head);
    // printf("\n");
    // printf("After Deletion from End: \n");
    // LinkdeListTraversal(head);

    printf("\n");
    head = DeleteKey(head, 30);
    LinkdeListTraversal(head);
}