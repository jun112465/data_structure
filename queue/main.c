#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    init(q);

    for(int i=0; i<3; i++){
        enqueue(q, i+1);
    }

    for(int i=0; i<10; i++){
        enqueue(q, i+1);
        dequeue(q);
    }

    for(int i=0; i<SIZE; i++)
        printf("%d ", q->data[i]);
    printf("\n");

    return 0;
}