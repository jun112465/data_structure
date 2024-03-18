#include "linkedlist.h"

int main(){
    List *L = malloc(sizeof(List));
    init(L);

    for(int i=0; i<5; i++){
        add(L, i+1);
    }

    print_list(L);

    add_by_index(1, L, 11);
    add_by_index(4, L, 12);
    add_by_index(100, L, 13);

    print_list(L);

    return 0;
}