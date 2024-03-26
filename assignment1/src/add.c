#include "personal.h"

void Add(PINFO_LIST list, PPERSON_INFO person){


    printf("[ADD, PERSON] : [%s, %d, %s]\n", person->szNam, person->nAge, person->szPhone);
    // add on memory
    list->arr[list->size] = *person;

    // add on file
    // FILE *fp = fopen(LIST_FILE, "ab");
    // if(fp == NULL) {
    //     printf("Unable to open file\n");
    //     exit(1);
    // }
    // fwrite(person, sizeof(PERSON_INFO), 1, fp);
    // fclose(fp);

    // add size
    list->size++;
}