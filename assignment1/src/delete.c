#include "personal.h"

int equal(PPERSON_INFO, PPERSON_INFO);
void delete_from_file(PINFO_LIST);

void Delete(PINFO_LIST list, int index){

    // 잘못된 index에 대한 에외처리 하기.
    int find = 0;
    PERSON_INFO person = list->arr[index];

    for(int i=index-1; i<list->size-1; i++){
        list->arr[i] =  list->arr[i+1];
    }

    printf("[DELETED] name : %s, age : %d, phone : %s\n\n", 
        person.szNam, person.nAge, person.szPhone);

    list->size--;
}



void delete_from_file(PINFO_LIST list){
    FILE *fp;

    remove(LIST_FILE);

    fp = fopen(LIST_FILE, "wb");
    fwrite(list->arr, sizeof(PERSON_INFO), list->size, fp);

    fclose(fp);
}
