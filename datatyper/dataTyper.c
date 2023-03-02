#include <stdio.h>

int main(){

    char * ptr;

    *ptr = 42;

    printf("this easy to understand\n", ptr);
    printf("int: %d\n", ptr);
    printf("pointer: %p\n", ptr);
    printf("char: %c\n", ptr);
    printf("int: %d\n", *ptr);
    printf("pointer: %p\n", *ptr);
    printf("char: %c\n", *ptr);

    return 0;
}