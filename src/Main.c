#include "npArrayDef.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
    Array* arr = calloc(1, sizeof(Array));
    for (int count = 1; argv[count] != NULL; count++)
    {
        arr->dimensionCount++;
    }
    printf("%d\n", arr->dimensionCount);
        char character = '.';
        if (strchr(argv[1], character) != NULL) {
        printf("The string contains the character '%c'\n", character);
    } else {
        printf("The string does not contain the character '%c'\n", character);
    }
    return 0;
}