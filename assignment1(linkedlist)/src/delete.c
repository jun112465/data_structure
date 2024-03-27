#include "personal.h"
#include "linkedlist.h"

void Delete(PLIST list, int index){
    PNODE curnode = list->head;
    PNODE tmp;
    int i;

    for(i=0; curnode->next!=NULL || i==index; i++){
        curnode = curnode->next;
    }

    if(i == index){
        tmp = curnode->next;
        curnode = curnode->next->next; 
        free(tmp);
    }
}