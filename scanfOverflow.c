#include <stdio.h>

int main(){
    char* buffer;
    int check = 0;

    printf("enter text: ");
    scanf_s("%s", buffer);
    if (check)
    {
        printf("Passed!");
    }else{
        printf("Denied");
    }
    

    return 0;
}