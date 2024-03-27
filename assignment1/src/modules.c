#include "personal.h"

void add_dummy_data(PINFO_LIST plist){
    PERSON_INFO person;
    person.nAge = 27;
    snprintf(person.szNam, MAX_NAME_LENGTH, "John Doeabcdefghijklmn");
    snprintf(person.szPhone, MAX_PHONE_LENGTH, "123-456-7890");
    Add(plist, &person);
    

    PERSON_INFO person1;
    person1.nAge = 26;
    snprintf(person1.szNam, MAX_NAME_LENGTH, "abcdefghijklmn");
    snprintf(person1.szPhone, MAX_PHONE_LENGTH, "123-456-7890");
    Add(plist, &person1);
}

int equal(PPERSON_INFO p1, PPERSON_INFO p2){

    if(p1->nAge == p2->nAge
    && strcmp(p1->szNam, p2->szNam)==0
    && strcmp(p1->szPhone, p2->szPhone)==0)
        return 1;
        
    return 0;
}

// update file data with memory list
void update_file(PINFO_LIST list){
    FILE *fp;

    remove(LIST_FILE);

    fp = fopen(LIST_FILE, "wb");
    fwrite(list->arr, sizeof(PERSON_INFO), list->size, fp);

    fclose(fp);
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
    return 1; // 모든 문자가 알파벳인 경우 성공
}