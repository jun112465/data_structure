#include "priority-queue.h"

PriorityQueue* create_queue(){
    return (PriorityQueue*)calloc(sizeof(PriorityQueue), 1);
}
struct node* create_node(int data, int priority){
    struct node *p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->priority = priority;
}
void enqueue(PriorityQueue *pq, struct node *node){

    pq->heap[pq->size++] = *node;
    int parent = pq->size / 2;
    int child = pq->size;
    while(parent>0 && pq->heap[parent].priority < pq->heap[child].priority){
        struct node tmp = pq->heap[parent];
        pq->heap[parent] = pq->heap[child];
        pq->heap[child] = tmp;

        child = parent;
        parent = child / 2;
    }
}

void dequeue(PriorityQueue *pq){
    if(pq->size < 1) {
        perror("empty queue\n");
        exit(1);
    }
    pq->heap[1] = pq->heap[pq->size--];

    int parent = 1;
    int child = 2;
    while(parent*2 < pq->size && pq->heap[parent].priority < pq->heap[parent*2].priority){
        if(pq->size >= parent*2+1){
           child = pq->heap[parent*2].priority>pq->heap[parent*2+1].priority 
           ? 
           child : child+1;
        }

        struct node tmp = pq->heap[child];
        pq->heap[child] = pq->heap[parent];
        pq->heap[parent] = tmp;

        parent = child;
        child = child*2;
    }
}