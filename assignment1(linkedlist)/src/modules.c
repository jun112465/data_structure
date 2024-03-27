#include "personal.h"

PPERSON_INFO get_person_info(char *input_buffer){
    PPERSON_INFO person;

    person = malloc(sizeof(PERSON_INFO));

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

int validate_input(const char *str, int type) {
    int (*handler_ptr)(int);

    switch(type){
        case 1: 
            // check all char is alphabet
            handler_ptr = isalpha;
            break;
        case 2:
            // check all char is digit
            handler_ptr = isdigit;
            break;
        default:
            return 0;
    }

    if (str == NULL) return 0; // NULL 포인터가 입력되면 실패로 처리

    while (*str != '\0'){
        if (!handler_ptr(*str))
            return 0; // 알파벳이 아닌 문자가 포함된 경우 실패로 처리
        str++;
    }
    return 1; // 모든 문자가 알파벳이거나 숫자인 경우 성공
}

int get_int(char *input_buffer){
    fgets(input_buffer, INPUT_BUFFER_SIZE, stdin);
    input_buffer[strlen(input_buffer) - 1] = '\0'; // 개행 문자 제거
    return atoi(input_buffer);
}