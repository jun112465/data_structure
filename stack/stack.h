#pragma once

#include <stdlib.h>
#include <stdio.h>

#define SIZE 5

typedef int element;

typedef struct {
    int top;
    element data[SIZE];
}Stack;


void init(Stack*);
int is_full(Stack*);
int is_empty(Stack*);

element pop(Stack*);
element peek(Stack*);
void push(Stack*, element);