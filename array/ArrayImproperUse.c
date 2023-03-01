#include <stdio.h>
#include <stdlib.h>

char getLetter(char* word, int place){
    return word[place];
}

int main(int argc, char** argv){
    char* word = argv[1];
    int place = atoi(argv[2]);
    char* secret = "super secret";
    printf("out : %c\n", getLetter(word, place));
    for (int i = 0; i < 100; i++)
    {
        printf("%c", getLetter(word, i));
    }
    

    return 0;
}