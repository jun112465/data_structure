#include "personal.h"

PINFO_LIST Load(){

    print_function("LOAD");

    FILE *fp;
    PINFO_LIST list;

    // initialize list 
    list = (PINFO_LIST)malloc(sizeof(INFO_LIST));
    list->arr = (PPERSON_INFO)calloc(sizeof(PERSON_INFO), MAX_LIST_LENGTH);

    // open file 
    fp = fopen(LIST_FILE, "ab+");
    if(fp == NULL) {
        printf("Unable to open file\n");
        exit(-1);
    }

    // read and load date from file to arr
    // size에 대한 예외처리 해야함.
    
    list->size = 0;
    while(fread(&list->arr[list->size], sizeof(PERSON_INFO), 1, fp) == 1) list->size++;
    fclose(fp);

    return list;
}