#include <stdio.h>
#include <stdlib.h>


int main(){
    char *str = "1212312312312312412412312314123123123124312";
    printf("%d ", atoi(str));
    printf("%ld", strtol(str, NULL, 10));
    return 0;
}