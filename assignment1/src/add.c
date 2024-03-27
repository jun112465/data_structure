#include "personal.h"

void Add(PINFO_LIST list, PPERSON_INFO person){

    // overflow handling
    // if(list->size >= MAX_LIST_LENGTH){
    //     printf("[EXCEPTION] list is full\n");
    //     return;
    // }

    // add on memory
    list->arr[list->size] = *person;

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


    // free memory
    free(person);
}