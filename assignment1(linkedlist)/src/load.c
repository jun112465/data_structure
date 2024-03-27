#include "personal.h"

PINFO_LIST Load(){
    PERSON_INFO person;
    PINFO_LIST list;
    FILE *fp;

    list = (PINFO_LIST*)malloc(sizeof(INFO_LIST));
    list->head = (PERSON_INFO*)malloc(sizeof(PERSON_INFO));
    list->head->next = NULL;
    list->size = 0;

    fp = fopen(LIST_FILE, "ab+");
    if(fp == NULL) {
        printf("Unable to open file\n");
        exit(-1);
    }

    // load to memory
    while(1){
        int n;
        PPERSON_INFO person = (PPERSON_INFO)malloc(sizeof(PERSON_INFO));

        n = fread(person, sizeof(PERSON_INFO), 1, fp);
        Add(list, person);

        if(n == 0) break;
    }

    return list;
}