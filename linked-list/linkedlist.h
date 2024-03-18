#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef int element;

typedef struct node{
    struct node *next;
    element data;
}Node;


typedef struct linkedlist{
    Node *head;
    Node *tail;
    int size;
}List;

void init(List *);
int is_empty(List *);
void print_list(List *);

void add(List *, element);
void add_by_index(int, List *, element);

