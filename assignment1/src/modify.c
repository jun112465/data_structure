#include "personal.h"

void Modify(PINFO_LIST list, PPERSON_INFO after, PPERSON_INFO before){

    if(after==NULL || before==NULL) return;

    int flag = 0;

    // find target
    for(int i=0; i<list->size; i++){
        if((flag = equal(&list->arr[i], before)) == 1){
            list->arr[i] = *after;
            break;
        }
    }

    
    if(flag == 1){
        printf("[BEFORE] name : %s, age : %d, phone : %s\n",
               before->szNam, before->nAge, before->szPhone);
        printf("[AFTER] name : %s, age : %d, phone : %s\n",
               after->szNam, after->nAge, after->szPhone);

        update_file(list);
    }else{
        printf("[NOT FOUND] name : %s, age : %d, phone : %s\n",
               before->szNam, before->nAge, before->szPhone);
    }

    free(before);
    free(after);

}


