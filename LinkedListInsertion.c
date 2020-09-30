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
struct Node *insertAtBeginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}
// Case 2:
struct Node *insertAtIndex(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}
// Case 3:
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p = head;
    ptr->data = data;
    while (p->next != NULL)
    {
        /* code */
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
// Case 4:
struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;

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

    printf("Original List: ");
    LinkdeListTraversal(head);
    printf("\n");
    printf("After Insertion after a Node: ");
    head = insertAfter(head, second, 70);
    LinkdeListTraversal(head);
    printf("\n");
    head = insertAtBeginning(head, 10);
    printf("After Insertion at beginning: ");
    LinkdeListTraversal(head);
    printf("\n");
    printf("After Insertion at given index: ");
    head = insertAtIndex(head, 2, 25);
    LinkdeListTraversal(head);
    printf("\n");
    printf("After Insertion at given index: ");
    head = insertAtIndex(head, 5, 45);
    LinkdeListTraversal(head);
    printf("\n");
    printf("After Insertion at end: ");
    head = insertAtEnd(head, 70);
    LinkdeListTraversal(head);
}