#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};
// int isEmpty(struct Stack s)
int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// int isFull(struct Stack s)
int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct Stack *s, int val)
{
    if (isFull(s))
        printf("\nStack Overflow");
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}
//upar se index ka value dega.
int peek(struct Stack *s, int index)
{
    int arrayIndex = s->top - index + 1;
    if (arrayIndex < 0)
        printf("\nInvalid Index");
    else
    {
        return s->arr[arrayIndex];
    }
}
int StackTop(struct Stack *s)
{
    return s->arr[s->top];
}
int StackBottom(struct Stack *s)
{
    return s->arr[0];
}
int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 6;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    // struct Stack s;
    // s.size = 6;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));
    printf("\nBefore Pushing: \n");
    printf("\tFull(1) | Not Full(0) --> %d", isFull(s));
    printf("\n");
    printf("\tEmpty(1) | Not Empty(0) --> %d", isEmpty(s));
    printf("\n");
    // push(s, 10);
    // push(s, 11);
    push(s, 12);
    push(s, 13);
    push(s, 14);
    push(s, 15);
    push(s, 16);

    // printf("\nAfter Pushing: \n");
    // printf("\tFull(1) | Not Full(0) --> %d", isFull(s));
    // printf("\n");
    // printf("\tEmpty(1) | Not Empty(0) --> %d", isEmpty(s));
    // printf("\nPopped element: %d", pop(s));
    for (int i = 1; i <= s->top + 1; i++)
        printf("%d ", peek(s, i));

    printf("\nStack Top = %d", StackTop(s));
    printf("\nStack Bottom = %d", StackBottom(s));
}
