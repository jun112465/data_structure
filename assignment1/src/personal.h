#ifndef PERSONAL_H
#define PERSONAL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LIST_FILE "infolist"
#define MAX_NAME_LENGTH 10
#define MAX_PHONE_LENGTH 20
#define MAX_LIST_LENGTH 5

typedef struct __tPersonalInfo{

    int nAge;
    char szNam[MAX_NAME_LENGTH+1];
    char szPhone[MAX_PHONE_LENGTH+1];

} PERSON_INFO, *PPERSON_INFO;

typedef struct __tPersonalInfoList{
    PERSON_INFO *arr;
    int size;
} INFO_LIST, *PINFO_LIST;

// load info to linkedlist
PINFO_LIST Load();
// add info to linkedlist and update file
void Add(PINFO_LIST, PPERSON_INFO);
// delete node from linkedlist and update file
void Delete(PINFO_LIST, int index);
// modify node info and update file
void Modify(PINFO_LIST, PPERSON_INFO, PPERSON_INFO);
// print all info
void PrintInfo(PINFO_LIST);
// close main
void Close();

void add_dummy_data(PINFO_LIST);
int equal(PPERSON_INFO p1, PPERSON_INFO p2);
void update_file(PINFO_LIST list);
void print_function(char *);



#endif