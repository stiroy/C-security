#include <stdio.h>
#include <string.h>

int main(int argc, char** argv){
    char data[50];
    strcpy(data, argv[1]);

    printf("the input\n");
    printf("%s", data);

    return 0;
}