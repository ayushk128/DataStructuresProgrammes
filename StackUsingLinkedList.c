#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node * next;
};
struct Node * top = NULL;
void StackTaversal(struct Node *top)
{
    printf("Data in stack is: \n");
    while (top != NULL)
    {
        printf("Element: %d\n", top->data);
        top = top->next;
    }
}
int isEmpty(struct Node * top){
    if(top == NULL)
        return 1;
    else
        return 0;
}
int isFull(struct Node * top){
    struct Node * p = (struct Node *)malloc(sizeof(struct Node));
    if(p == NULL)
        return 1;
    else
        return 0;
}
struct Node *push(struct Node * top, int val){
    if(isFull(top))
        printf("\nStack Overflow");
    else{
        struct Node * n = (struct Node *)malloc(sizeof(struct Node));
        n->data = val;
        n->next = top;
        top = n;
        return top;
    }
}
int pop(struct Node * tp){
    if(isEmpty(tp)){
        printf("\nStack Underflow");
    }
    else{
        struct Node * p = tp;
        top = tp->next;
        int x = p->data;
        free(p);
        return x;
    }
}
int peek(int index){
    struct Node * p = top;
    for(int i = 0; (i<index-1 && p != NULL); i++)
        p = p->next;
    if(p != NULL)
        return p->data;
    else
        return -1;
}
int StackTop(){
    if(top != NULL)
        return top->data;
    else
        return -1;
}
int StackBottom(){
    struct Node * p = top;
    if(isEmpty(p))
        return -1;
    else{
    while(p->next != NULL){
        p = p->next;
    }
    return p->data;
    }

}
int main(){
    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);
    top = push(top, 50);
    StackTaversal(top);
    int element = pop(top);

    // printf("\nAfter popping, element is: %d", element);
    // StackTaversal(top);
    // printf("Element 1: %d\n", peek(1));
    // printf("Element 2: %d\n", peek(2));
    // printf("Element 3: %d\n", peek(3));
    printf("Top element: %d\n", StackTop());
    printf("Bottom Element: %d\n", StackBottom());
}