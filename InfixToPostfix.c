#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack{
    int size;
    int top;
    char *arr;
};
int Operator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    else return 0;
}
int Precedance(char a){
    if(a == '*' || a == '/')
        return 3;
    else if(a == '+' || a == '-')
        return 2;
    else return 0;
    
}
int isEmpty(struct Stack * sp){
    if(sp->top == -1)
        return 1;
    else return 0;
}
int isFull(struct Stack * sp){
    if(sp->top == sp->size - 1)
        return 1;
    else return 0;
}
void push(struct Stack * sp, char a){
    if(isFull(sp))
        printf("\nStack overflow");
    else{
        sp->top++;
        sp->arr[sp->top] = a;
    }
}
char pop(struct Stack * sp){
    if(isEmpty(sp)){
        printf("Stack underflow");
        return -1;
    }
    else{
        char popped = sp->arr[sp->top];
        sp->top --;
        return popped;
    }

}
char StackTop(struct Stack * sp){
    return sp->arr[sp->top];
}
char *InfixToPostfix(char *infix){
    struct Stack * sp = (struct Stack*)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0;  //for traversing the infix expression.
    int j = 0; //for  traversing the postfix expression.
    while(infix[i] != '\0'){
        if(!Operator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else{
            if(Precedance(infix[i]) >Precedance(StackTop(sp))){
                push(sp, infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(sp);
                j++;
            }
            
        }
    }
    while(!isEmpty(sp)){
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main(){
    char *infix = "a-b+t/d";
    printf("%s", InfixToPostfix(infix));
}