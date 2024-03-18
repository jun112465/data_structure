#include <stdio.h>
#include "stack.h"

int main() {

    Stack* s = (Stack*)malloc(sizeof(Stack));
    int popped;

    init(s);
    printf("%d \n", s->top);
    
    push(s, 3);
    peek(s);
    if ((popped = pop(s))) 
        printf("popped : %d\n", popped);
    if ((popped = pop(s)))
        printf("popped : %d\n", popped);

    for (int i = 0; i < SIZE + 1; i++) {
        push(s, i + 10);
    }

    return 0;
}