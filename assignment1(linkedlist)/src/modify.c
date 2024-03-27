#include "personal.h"
#include "linkedlist.h"

void Modify(PLIST list, int index, PPERSON_INFO p){
    PNODE curnode = list->head; 
    PPERSON_INFO tmp;
    int i;

    for(i=0; curnode->next!=NULL || i==index; i++){
        curnode = curnode->next;
    }

    if(i == index){
        tmp = curnode->next->person;
        curnode->next->person = p;
        free(tmp);
    }
}