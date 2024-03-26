#include "personal.h"


void Close(PINFO_LIST);
void CLI(PINFO_LIST);
PPERSON_INFO getInput();

int main(){
    PINFO_LIST plist = NULL;
    plist = Load();
    CLI(plist);
    Close(plist);
    return 0;
}

void CLI(PINFO_LIST list){

    while(1){
        char user_input[MAX_PHONE_LENGTH];
        int input;
        int index;
        PPERSON_INFO p1, p2;

        printf("\n**INSERT TASK NUMBER**\n\n");
        printf("1. [ADD]\n");
        printf("2. [DELETE]\n");
        printf("3. [MODIFY]\n");
        printf("4. [PRINT]\n");
        printf("5. [CLOSE]\n");

        printf("\nINPUT : ");

        fgets(user_input, sizeof(user_input), stdin);
        user_input[strlen(user_input)-1] = '\0'; // 개행 문자 제거
        input = atoi(user_input);

        switch(input){
            case 1:
                //p1 = getInput();
                Add(list, getInput());
                break;
            case 2:
                printf("INSERT INDEX : ");
                scanf("%d", &index);
                Delete(list, index);
                break;
            case 3:
                p1 = getInput();
                p2 = getInput();
                Modify(list, p1, p2);
                break;
            case 4:
                PrintInfo(list);
                break;
            case 5:
                exit(1);
                break;
            default:
                break;
        }
    }
}


void Close(PINFO_LIST list){
    print_function("CLOSE");
    if(list != NULL)
        update_file(list);

    PrintInfo(list);

    printf("\n");
}


PPERSON_INFO getInput(){
    PPERSON_INFO person;
    char user_input[10];

    person = malloc(sizeof(PERSON_INFO));

    printf("[NAME] : ");
    fgets(person->szNam, sizeof(person->szNam), stdin);
    person->szNam[strlen(person->szNam)-1] = '\0';

    printf("[AGE] : ");
    fgets(user_input, sizeof(user_input), stdin);
    user_input[strlen(user_input)-1] = '\0'; // 개행 문자 제거
    person->nAge = atoi(user_input);

    printf("[PHONE] : ");
    fgets(person->szPhone, sizeof(person->szPhone), stdin);
    person->szPhone[strlen(person->szPhone)-1] = '\0';


    printf("[PERSON] : [%s, %d, %s]\n", 
    person->szNam, person->nAge, person->szPhone);

    return person;
}