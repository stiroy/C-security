#include <stdio.h>

int main(int argc, char** argv){

    char string[10];
    int check = 0;

    sscanf_s(argv[1], "%s", &string);
    printf("string: %s\nCheck: %d\n", string, check);
    return 0;
}