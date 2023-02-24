#include <stdio.h>
#include <windows.h>

//this is an example of code that cause a infinity loop if you optimaze it

// function that waits 1 second before changing the value of the 
// variable
DWORD WINAPI Func(void* ptr){
    sleep(1);
    *(int*)ptr = 0;
}

int main(){
    int wait = 1; 
    printf("please wait while your getting auth\n");
    HANDLE thread = CreateThread(NULL, 0, Func, &wait, 0, NULL);
    while (wait);

    printf("program is done\n");

    return 0;
}