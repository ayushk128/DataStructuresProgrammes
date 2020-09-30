#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};
int isFull(struct Queue *q){
    if(q->rear == q->size - 1)
        return 1;
    else return 0;
}
int isEmpty(struct Queue *q){
    if(q->front == q->rear)
        return 1;
    else return 0;
}
void enqueue(struct Queue *q, int data){
    if(isFull(q))
        printf("The queue is full");
    else{
        q->rear++;
        q->arr[q->rear] = data;
    }
}
int dequeue(struct Queue * q){
    int a = -1;
    if(isEmpty(q))
        printf("Queue is empty");
    else{
        q->front++;
        a = q->arr[q->front];
    }
    return a;
}
int main(){
    struct Queue q;
    q.size = 4;
    q.front = q.rear = -1;
    q.arr = (int *)malloc(q.size * sizeof(int *));
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    printf("%d\n", dequeue(&q));
    enqueue(&q, 50);
    // if(isFull(&q))
    //     printf("\nQueue is full");
    // else
    //     printf("\nQueue is not full");
    // if(isEmpty(&q))
    //     printf("\nQueue is Empty");
    // else
    //     printf("\nQueue is not Empty");
}