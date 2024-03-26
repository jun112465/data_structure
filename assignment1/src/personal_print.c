#include "personal.h"

void PrintInfo(PINFO_LIST plist){
    // FILE *fp;
    // PERSON_INFO tmp[MAX_LIST_LENGTH];

    print_function("PRINT INFO");
    printf("[index] : [name, age, phone]\n");
    for (int i = 0; i < plist->size; i++){
        PPERSON_INFO person = &plist->arr[i];
        printf("[%d] : [%s, %d, %s]\n", 
        i+1, person->szNam, person->nAge, person->szPhone);
    }


    // printf("PRINT FROM FILE----------------------------\n");
    // fp = fopen(LIST_FILE, "rb");
    // fread(tmp, sizeof(PERSON_INFO), MAX_LIST_LENGTH, fp);
    // fclose(fp);
    // for(int i=0; i<plist->size; i++){
    //     printf("name : %s, age : %d, phone : %s\n", tmp[i].szNam, tmp[i].nAge, tmp[i].szPhone);
    // }

    printf("\n");

}