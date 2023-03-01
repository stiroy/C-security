#include <stdio.h>
#include <string.h>

// this program shows a simple program with a stack overflow 
// exploit. by writting AAAAxAAAAx1 will you pass the validation

void printAdressesForString(char*);

int main (){
    // Variables
    char secretCode[5] = "pass";
    char inputData[5];
    int pass = 0; // check variable

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
/**
 * prints the memory and the character until null is found
 * @param str char pointer to the memory space
 * @todo Better text out put for easier readablity
*/
void printAdressesForString(char* str){
    printf("Memory for String\n");
    for (char* stringPointer = str ; *stringPointer != '\0' ; stringPointer += sizeof(char)){
        printf("%p : %c\n", stringPointer, *stringPointer);
    }
    
}