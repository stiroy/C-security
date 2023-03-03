#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

char* hexToAscii(const char* hexStr) {
    size_t len = strlen(hexStr);
    char* asciiStr = malloc(len/2 + 1);
    size_t j = 0;

    for (size_t i = 0; i < len; i += 2) {
        char hexByte[3] = {hexStr[i], hexStr[i+1], '\0'};
        int byteValue = (int) strtol(hexByte, NULL, 16);
        asciiStr[j++] = (char) byteValue;
    }

    asciiStr[j+1] = '\0';
    return asciiStr;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <program> <hex string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* program = argv[1];
    char* hexStr = argv[2];
    char* asciiStr = hexToAscii(hexStr);

    // Construct the command line as a single string
    size_t cmdLineLen = strlen(program) + strlen(asciiStr) + 3; // include the quotes and the space
    char* cmdLine = malloc(cmdLineLen);
    snprintf(cmdLine, cmdLineLen, "\"%s\" %s", program, asciiStr);

    // Launch the program with the ascii string as the first argument
    PROCESS_INFORMATION pi;
    STARTUPINFO si;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    if (!CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        fprintf(stderr, "Failed to launch program %s\n", program);
        exit(EXIT_FAILURE);
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD exitCode;
    GetExitCodeProcess(pi.hProcess, &exitCode);

    printf("Program exited with code %d\n", exitCode);

    free(asciiStr);
    free(cmdLine);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return 0;
}
