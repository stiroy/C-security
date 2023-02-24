#include <stdio.h>
#include <string.h>

void printAdressesForString(char*);

int main (){
    char secretCode[5] = "pass";
    char inputData[5];
    int pass = 0;

    printf("Please Write in the code\n");
    gets(inputData);

    if (strcmp(secretCode, inputData) == 0){
        printf("pass!\n");
        pass = 1;
    }

    if (pass){
        printf("access!\n");
    } else{
        printf("Denied\n");
    }
    printf("SecretCode: %p, input: %p\n", &secretCode, &inputData);
    printf("secretCode: %s\n", secretCode);
    printf("input: %s\n", inputData);
    printAdressesForString(inputData);
    printAdressesForString(secretCode);

    return 0;
}

void printAdressesForString(char* str){
    printf("Memory for String\n");
    for (char* stringPointer = str ; *stringPointer != '\0' ; stringPointer += sizeof(char)){
        printf("%p : %c\n", stringPointer, *stringPointer);
    }
    
}