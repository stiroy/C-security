#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

    int num = 42;
    float * ptr = (float*)num;

    printf("this easy to understand\n", ptr);
    printf("Pointer\n", ptr);
    printf("int: %d\n", ptr);
    printf("pointer: %p\n", ptr);
    printf("char: %c\n", ptr);
    printf("float: %f\n", ptr);
    

    return 0;
}