/*
 * Implement your solution in this file
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"

char* readString(char* fileName) {

    char *pInput = (char*) malloc(MAX_LINE_LEN * sizeof(char));

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
    int memoryToCalloc = ((strLength*(strLength+1))/2);

    char* pBuffer =calloc(memoryToCalloc,sizeof(char));

    if (pBuffer == NULL) {
        return NULL;
    }

    /*For "code" runs till i=3 0,1,2,3 */
    for (int i=0; i<strLength; i++)
    {
        /* runs till s runs into index i
         * appends each element to buffer
         * each loop increases whats appeneded to buffer
         * Future improvement: Use single forloop and strncpy */
        for(int s=0; s<=i; s++)
        {
            strcpy(pBuffer, strncat(pBuffer, &str[s],1));
        }
    }

    return pBuffer;
}
