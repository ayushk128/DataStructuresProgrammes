#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int size;
    int top;
    char *arr;
};
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
void push(struct Stack *s, char val)
{
    if (isFull(s))
        printf("\nStack Overflow, Cannot push the %c character.", val);
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}
char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Underflow");
        return -1;
    }
    else
    {
        char val = s->arr[s->top];
        s->top--;
        return val;
    }
}
int matched(char a, char b){
    if(a == '{' && b == '}')
        return 1;
    else if(a == '[' && b == ']')
        return 1;
    else if(a == '(' && b == ')')
        return 1;
    else
        return 0;
}
int parenthesisMatched(char *exp){
    struct Stack * sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size*sizeof(char));
    char popped;

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '('){
            push(sp, exp[i]);
        }
        else if(exp[i] == '}' || exp[i] == ']' || exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            popped = pop(sp);
            if(!matched(popped, exp[i]))
                return 0;
        }
    }
    if(isEmpty(sp)) return 1;
    else return 0;
}
int main()
{
    char *exp = "{[()]}";
    if(parenthesisMatched(exp))
        printf("\nThe parenthesis is balanced.");
    else
        printf("\nThe parenthesis is not balanced.");
}