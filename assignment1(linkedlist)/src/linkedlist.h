#include "personal.h"

typedef struct node{
    PPERSON_INFO person;
    struct node *next;
}NODE, *PNODE;

typedef struct linkedlist{
    PNODE head;
    int size;
}LIST, *PLIST;