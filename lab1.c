/*
 * Implement your solution in this file
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readString(char* fileName) {

    char *pInput = (char*) malloc(100 * sizeof(char));

    FILE *pFile = fopen(fileName, "r");
    fgets(pInput, 100, pFile);

    if (pInput == NULL) {
        return NULL;
    }

    pInput[strcspn(pInput, "\n")] = 0;

    fclose(pFile);
    return pInput;

}
char* mysteryExplode(const char* str) {
    /* Length of input string (4 for 'code') */
    const int strLength = strlen(str);

    /* This was an optimization of the while loop*/
    int memoryToMalloc = ((strLength*(strLength+1))/2);

    char *buffer = (char*) malloc(memoryToMalloc * sizeof(char));

    for (size_t i = 0; i <= strLength; i++) {
        strncpy(buffer, str, i);
    }
    buffer[memoryToMalloc] = '\0';

    return buffer;
}
