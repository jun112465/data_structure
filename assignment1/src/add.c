#include "personal.h"

void Add(PINFO_LIST list, PPERSON_INFO person){

    // add on memory
    list->arr[list->size].nAge = person->nAge;
    snprintf(list->arr[list->size].szNam, MAX_NAME_LENGTH, person->szNam);
    snprintf(list->arr[list->size].szPhone, MAX_NAME_LENGTH, person->szPhone);


    // add on file
    FILE *fp = fopen(LIST_FILE, "ab");
    if(fp == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }
    fwrite(person, sizeof(PERSON_INFO), 1, fp);
    fclose(fp);

    // add size
    list->size++;
}