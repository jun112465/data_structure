#include "personal.h"

#define INPUT_BUFFER_SIZE 1024

void Close(PINFO_LIST);
void CLI(PINFO_LIST);

int get_int(char*);
PPERSON_INFO get_person_info(char*);

int main(){
    // initialize list
    PINFO_LIST plist = NULL;
    plist = Load();
    
    // open cli
    CLI(plist);

    // save memory to file
    Close(plist);

    return 0;
}

void CLI(PINFO_LIST list){
    // buffer for every input
    char input_buffer[INPUT_BUFFER_SIZE] = {'\0',};
    int task_no;
    PPERSON_INFO p1, p2;

    while(1){

        printf("\n**INSERT TASK NUMBER**\n\n");
        printf("1. [ADD]\n");
        printf("2. [DELETE]\n");
        printf("3. [MODIFY]\n");
        printf("4. [PRINT]\n");
        printf("5. [CLOSE]\n");

        printf("\n[INPUT] ");

        // fgets(input_buffer, INPUT_BUFFER_SIZE, stdin);
        // input_buffer[strlen(input_buffer)-1] = '\0'; // 개행 문자 제거
        // task_no = atoi(input_buffer);
        task_no = get_int(input_buffer);


        switch(task_no){
            case 1:
                printf("[TASK] ADD\n");
                Add(list, get_person_info(input_buffer));
                break;
            case 2:
                printf("[TASK] DELETE\n");
                printf("[INSERT INDEX] ");
                Delete(list, get_int(input_buffer));
                break;
            case 3:
                printf("[TASK] MODIFY\n");
                printf("[TARGET]\n");
                p1 = get_person_info(input_buffer);
                printf("[UPDATE TO]\n");
                p2 = get_person_info(input_buffer);
                Modify(list, p2, p1);
                break;
            case 4:
                printf("[TASK] PRINT\n");
                PrintInfo(list);
                break;
            case 5:
                printf("[TASK] CLOSE\n");
                return;
            default:
                printf("[EXCEPTION] WRONG INPUT\n");
                break;
        }
    }
}


void Close(PINFO_LIST list){
    if(list != NULL)
        update_file(list);

    PrintInfo(list);

    free(list);
}

int get_int(char *input_buffer){
    fgets(input_buffer, INPUT_BUFFER_SIZE, stdin);
    input_buffer[strlen(input_buffer) - 1] = '\0'; // 개행 문자 제거
    return atoi(input_buffer);
}

PPERSON_INFO get_person_info(char *input_buffer){
    PPERSON_INFO person;

    person = malloc(sizeof(PERSON_INFO));

    // fgets() -> "hello\n\0" -> "hello\0\0"
    // 

    printf("[NAME]");
    printf("[MAX_LENGTH=%d] ", MAX_NAME_LENGTH);
    fgets(input_buffer, INPUT_BUFFER_SIZE, stdin);
    input_buffer[strlen(input_buffer) - 1] = '\0'; // 개행 문자 제거
    if(!validate_input(input_buffer, 1)){
        printf("[EXCEPTION] only alphabets are allowed\n");
        free(person);
        return NULL;
    }
    strncpy(person->szNam, input_buffer, MAX_NAME_LENGTH);
    person->szNam[MAX_NAME_LENGTH] = '\0';

    printf("[AGE] ");
    fgets(input_buffer, INPUT_BUFFER_SIZE, stdin);
    input_buffer[strlen(input_buffer) - 1] = '\0'; // 개행 문자 제거
    if(!validate_input(input_buffer, 2)){
        // NAN 
        printf("[EXCEPTION] only numbers are allowed\n");
        free(person);
        return NULL;
    }
    person->nAge = atoi(input_buffer);


    printf("[PHONE]");
    printf("[MAX_LENGTH=%d] ", MAX_PHONE_LENGTH);
    fgets(input_buffer, INPUT_BUFFER_SIZE, stdin);
    input_buffer[strlen(input_buffer) - 1] = '\0'; // 개행 문자 제거
    if(!validate_input(input_buffer, 2)){
        // NAN 
        printf("[EXCEPTION] only numbers are allowed\n");
        free(person);
        return NULL;
    }
    strncpy(person->szPhone, input_buffer, MAX_PHONE_LENGTH);
    person->szPhone[MAX_PHONE_LENGTH] = '\0';

    return person;
}