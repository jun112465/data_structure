#include "personal.h"
#include "linkedlist.h"

void Add(PLIST list, PNODE newnode){
    PNODE tmp = list->head;
    newnode->next = tmp;
    list->head->next = newnode;
}