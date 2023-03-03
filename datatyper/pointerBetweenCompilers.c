#include <stdio.h>

int main(){

    int interger;
    printf("interger: %d\nplace: %p\n", interger, &interger);

    int *tmp;
    *tmp = 42; 
    printf("test %d", **&*&*&*&*&*&*&*&*&*&tmp);
    return 0;
}