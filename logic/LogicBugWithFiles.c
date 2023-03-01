#include <stdio.h>
#include <string.h>

int Validate(char* username, char* password){
    char validPassword[64];
    FILE* passwordFile;
    char path[128] = "./user/";
    snprintf(path, sizeof(path), "./user/%s", username);
    passwordFile = fopen(path, "r");
    if (passwordFile == NULL)
    {
        fclose(passwordFile);
        return 0;
    }
    
    fscanf(passwordFile, "%s", validPassword);
    fclose(passwordFile);
    printf("validPassword: %s\n", validPassword);
    return strcmp(password, validPassword) == 0;
}

int main(){
    char userName[64];
    char password[64];


    printf("Enter username: ");
    scanf("%64s", userName);
    printf("Enter password: ");
    scanf("%64s", password);

    

    if (Validate(userName, password))
    {
        printf("Logged in!\n");
    }
    

    return 0;
}