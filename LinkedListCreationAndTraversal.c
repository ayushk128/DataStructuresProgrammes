#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char data;
    struct Node *next;
};

void LinkdeListTraversal(struct Node *ptr)
{
    printf("Data in linked list is: \n");
    while (ptr != NULL)
    {
        printf("%c", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    struct Node *sixth;

    struct Node *seventh;
    struct Node *eighth;
    struct Node *nineth;
    struct Node *tenth;
    struct Node *eleventh;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    sixth = (struct Node *)malloc(sizeof(struct Node));

    seventh = (struct Node *)malloc(sizeof(struct Node));
    eighth = (struct Node *)malloc(sizeof(struct Node));
    nineth = (struct Node *)malloc(sizeof(struct Node));
    tenth = (struct Node *)malloc(sizeof(struct Node));
    eleventh = (struct Node *)malloc(sizeof(struct Node));

    head->data = 'A';
    head->next = second;

    second->data = 'y';
    second->next = third;

    third->data = 'u';
    third->next = fourth;

    fourth->data = 's';
    fourth->next = fifth;

    fifth->data = 'h';
    fifth->next = sixth;

    sixth->data = ' ';
    sixth->next = seventh;

    seventh->data = 'K';
    seventh->next = eighth;

    eighth->data = 'u';
    eighth->next = nineth;

    nineth->data = 'm';
    nineth->next = tenth;

    tenth->data = 'a';
    tenth->next = eleventh;

    eleventh->data = 'r';
    eleventh->next = NULL;

    LinkdeListTraversal(head);
}