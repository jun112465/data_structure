#include "linkedlist.h"

void init(List *L){
    L->head = (Node*)malloc(sizeof(Node));
    L->tail = L->head;
    L->size = 0;
}

int is_empty(List *L){
    return L->head->next == NULL;
}

void print_list(List *L){
    Node *cur_node = L->head;
    while(cur_node->next != NULL)  {
        cur_node = cur_node->next;
        printf("%d ", cur_node->data);
    }
    printf("\n");
}

void add(List *L, element data){
    // 노드 생성 
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    // 추가
    L->tail->next = new_node;
    L->tail = new_node;
    L->size++;
}

void add_by_index(int idx, List *L, element data){
    // 노드 생성
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if(is_empty(L)){
        L->head->next = new_node;
        L->tail = new_node;
    }else {
        Node *cur_node = L->head;
        Node *tmp;

        for (int i = 0; i < idx; i++)
        {
            if (cur_node->next == NULL)
            {
                L->tail = new_node;
                break;
            }
            cur_node = cur_node->next;
        }

        tmp = cur_node->next;
        cur_node->next = new_node;
        new_node->next = tmp;
    }
}