#include <stdio.h>

// this Prgoram shows that it's possiable to do 
// stack overflow on scanf 
// input to pass the check is AAAAx1

int main(){
    //variables
    char buffer[5];
    int check = 0;

    printf("enter text: ");
    scanf("%s", buffer); // the problem is scanf format that isn't a set amount like %4s
    if (check)
    {
        printf("Passed!");
    }else{
        printf("Denied");
    }
    

    return 0;
}