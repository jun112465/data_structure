#pragma once
#include <stdio.h>

#define SIZE 5

typedef int element;

struct queue{
    int front;
    int rear;
    element data[SIZE];
};

void init(struct queue*);
int is_empty(struct queue*);
int is_full(struct queue*);

void enqueue(struct queue *, element data);
element dequeue(struct queue *);
element front(struct queue *);
element rear(struct queue *);