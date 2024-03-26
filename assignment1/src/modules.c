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

void update_file(PINFO_LIST list){
    FILE *fp;

    remove(LIST_FILE);

    fp = fopen(LIST_FILE, "wb");
    fwrite(list->arr, sizeof(PERSON_INFO), list->size, fp);

    fclose(fp);
}

void print_function(char *func_name){
    printf("[%s]\n", func_name);
}
/*
int main(){
    FILE *fp;
    fp = fopen(LIST_FILE, "wb");

    PERSON_INFO person;
    person.nAge = 27;
    snprintf(person.szNam, MAX_NAME_LENGTH, "John Doeabcdefghijklmn");
    snprintf(person.szPhone, MAX_PHONE_LENGTH, "123-456-7890");

    PERSON_INFO person1;
    person1.nAge = 26;
    snprintf(person1.szNam, MAX_NAME_LENGTH, "abcdefghijklmn");
    snprintf(person1.szPhone, MAX_PHONE_LENGTH, "123-456-7890");


    if(fp == NULL) {
        printf("Unable to open file\n");
        return 1;
    }

    fwrite(&person, sizeof(PERSON_INFO), 1, fp);
    fwrite(&person1, sizeof(PERSON_INFO), 1, fp);
    fclose(fp);


    fp = fopen(LIST_FILE, "rb");

    // 파일이 성공적으로 열렸는지 확인
    if (fp == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 파일로부터 데이터 읽기
    //PERSON_INFO person;
    fread(&person, sizeof(PERSON_INFO), 1, fp);
    printf("name : %s, age : %d, phone : %s\n", person.szNam, person.nAge, person.szPhone);

    fread(&person, sizeof(PERSON_INFO), 2, fp);
    printf("name : %s, age : %d, phone : %s\n", person.szNam, person.nAge, person.szPhone);



    return 0;
}
*/