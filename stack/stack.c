#include "stack.h"

void init(Stack* s) {
    s->top = -1;
}
int is_full(Stack* s) {
    return s->top == SIZE - 1;
}

int is_empty(Stack* s) {
    return s->top == -1;
}

element peek(Stack* s) {
    printf("top : %d\n", s->data[s->top]);
}

element pop(Stack* s) {
    if (is_empty(s)) {
        perror("stack is empty");
        return;
    }

    return s->data[s->top--];
}

void push(Stack* s, element data) {
    if (is_full(s)) {
        printf("stack is full, [%d] push failed", data);
        return;
    }
    s->data[++s->top] = data;
}