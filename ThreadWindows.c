#include <stdio.h>
#include <windows.h>

//this is an example of code that cause a infinity loop if you optimaze it

/**
 * Func sleeps for 1 sec then changes void pointer(int pointer)
 * value to zero
 * @param ptr is a int pointer
*/
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