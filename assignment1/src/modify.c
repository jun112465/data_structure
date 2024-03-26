#include "personal.h"

void Modify(PINFO_LIST list, int index, PPERSON_INFO after){
    //예외처리 하기.
    print_function("MODIFY");

    // 원래 index 보다 +1 된 값이 들어옴.
    index--;

    PERSON_INFO before = list->arr[index];
    list->arr[index] = *after;
    printf("[MODIFIED]\n");
    printf("[BEFORE] name : %s, age : %d, phone : %s\n",
           before.szNam, before.nAge, before.szPhone);
    printf("[AFTER] name : %s, age : %d, phone : %s\n\n",
           after->szNam, after->nAge, after->szPhone);
}


