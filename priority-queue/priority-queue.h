#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 1025

struct node{
    int data;
    int priority;    
};

typedef struct queue{
    struct node heap[MAX_DATA];
    int size;
}PriorityQueue;

PriorityQueue* create_queue();
struct node* create_node(int data, int priority);

void enqueue(PriorityQueue *, struct node *);
void dequeue();
struct node top();

