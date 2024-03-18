#include "queue.h"

void init(struct queue *q){
    q->front = 0;
    q->rear = 0;
}

int is_empty(struct queue* q){
    return q->front == q->rear;
}

int is_full(struct queue *q){
    return q->rear == SIZE;
}

void enqueue(struct queue *q, element data){
    if(is_full(q)){
        printf("QUEUE IS FULL\n");
    }else{
        q->data[q->rear++] = data;
        q->rear %= SIZE;
    }
}

element dequeue(struct queue *q){
    if(is_empty(q)){
        printf("QUEUE IS EMPTY");
        return -1;
    }
    else
    {
        int tmp = q->data[q->front++];

        q->front %= SIZE;

        return tmp;
    }
}

element front(struct queue *q){
    return q->data[q->front];
}

element rear(struct queue *q){
    return q->data[q->rear];
}

