#include <stdio.h>

int main(){

    //variables
    char buffer[5];
    int check = 0;

    printf("enter text: ");
    scanf_s("%s", buffer); // here you have 2 options %4s and add after buffer 5
    if (check)
    {
        printf("Passed!");
    }else{
        printf("Denied");
    }

    return 0;
}