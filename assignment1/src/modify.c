#include "personal.h"

void Modify(PINFO_LIST list, PPERSON_INFO before, PPERSON_INFO after){

    print_function("MODIFY");

    int flag = 0;
    for(int i=0; i<list->size; i++){
        if((flag = equal(&list->arr[i], before)) == 1){
            list->arr[i] = *after;
            break;
        }
    }

    if(flag == 1){
        printf("[MODIFIED]\n");
        printf("[BEFORE] name : %s, age : %d, phone : %s\n",
               before->szNam, before->nAge, before->szPhone);
        printf("[AFTER] name : %s, age : %d, phone : %s\n\n",
               after->szNam, after->nAge, after->szPhone);
    }else{
        printf("[NOT FOUND] name : %s, age : %d, phone : %s\n\n",
               before->szNam, before->nAge, before->szPhone);
    }
}


