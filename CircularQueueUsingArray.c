#include<stdio.h>
#include<stdlib.h>
struct circularQueue{
    int size;
    int front;
    int rear;
    int *arr;
};
int isFull(struct circularQueue *q){
    if((q->rear + 1) % q->size == q->front)
        return 1;
    else return 0;
}
int isEmpty(struct circularQueue *q){
    if(q->front == q->rear)
        return 1;
    else return 0;
}
void enqueue(struct circularQueue *q, int data){
    if(isFull(q))
        printf("The queue is full\n");
    else{
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = data;
    }
}
int dequeue(struct circularQueue * q){
    int a = -1;
    if(isEmpty(q))
        printf("Queue is empty");
    else{
        q->front = (q->front + 1) % q->size;
        a = q->arr[q->front];
    }
    return a;
}
int main(){
    struct circularQueue q;
    q.size = 4;
    q.front = q.rear = 0;   //this is aslo changed as compared to linear queue.
    q.arr = (int *)malloc(q.size * sizeof(int *));

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    // printf("%d\n", dequeue(&q));
    // printf("%d\n", dequeue(&q));
    // printf("%d\n", dequeue(&q));
    // printf("%d\n", dequeue(&q));
    enqueue(&q, 50);
    // dequeue(&q);
    if(isFull(&q))
        printf("\nQueue is full");
    else
        printf("\nQueue is not full");
    if(isEmpty(&q))
        printf("\nQueue is Empty");
    else
        printf("\nQueue is not Empty");
}