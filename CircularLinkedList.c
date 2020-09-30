#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void CircularLinkedListTraversal(struct Node *first)
{
    struct Node *ptr = first;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != first);
}
struct Node * InsertAtFirst(struct Node * head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head->next;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;

}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = head;
    head = InsertAtFirst(head, 10);
    CircularLinkedListTraversal(head);
}