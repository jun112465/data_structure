#include "personal.h"

// void Modify(PINFO_LIST list, PPERSON_INFO after, PPERSON_INFO before){

//     if(after==NULL || before==NULL) return;

//     int flag = 0;

//     // find target
//     for(int i=0; i<list->size; i++){
//         if((flag = equal(&list->arr[i], before)) == 1){
//             list->arr[i] = *after;
//             break;
//         }
//     }

    
//     if(flag == 1){
//         printf("[BEFORE] name : %s, age : %d, phone : %s\n",
//                before->szNam, before->nAge, before->szPhone);
//         printf("[AFTER] name : %s, age : %d, phone : %s\n",
//                after->szNam, after->nAge, after->szPhone);

//         update_file(list);
//     }else{
//         printf("[NOT FOUND] name : %s, age : %d, phone : %s\n",
//                before->szNam, before->nAge, before->szPhone);
//     }

//     free(before);
//     free(after);

// }

void Modify(PINFO_LIST list, int index, PPERSON_INFO person){
    if(index < 1 || index > list->size) {
        printf("[ERROR] index out of bound");
        return;
    }

    list->arr[index-1] = *person;

    free(person);
}

void modifyCLI(char *input_buffer, PINFO_LIST list){

    while(1){
        search(input_buffer, list);
        printf("[ALARM] search again? [Y/N]\n");
        printf("[INPUT] ");

        fgets(input_buffer, INPUT_BUFFER_SIZE, stdin);
        input_buffer[strlen(input_buffer)-1] = '\0';
        printf(" %s", input_buffer);

        if(strcmp(input_buffer, "N")==0 || strcmp(input_buffer, "n")==0) break;
    }




}

void change(char *input_buffer, PINFO_LIST list){
    int idx;

    printf("[INSERT INDEX] insert 0 to stop\n");
    printf("[INPUT] ");

    fgets(input_buffer, INPUT_BUFFER_SIZE, stdin);
    input_buffer[strlen(input_buffer)-1] = '\0';
    if(!validate_input(input_buffer, 2)){
        printf("[EXCEPTION] only numbers are allowed\n");
        return;
    }

    idx = atoi(input_buffer);
    if(idx <= 0) return;
    if(idx > list->size) {
        printf("[ERROR] index out of bound\n");
        return;
    }

    Modify(list, idx, get_person_info(input_buffer));
}