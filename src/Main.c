#include "npArrayDef.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
    Array* arr = calloc(1, sizeof(Array));
    for (int count = 1; argv[count] != NULL; count++)
    {
        arr->dimensionCount++;
    }
    printf("%d\n", arr->dimensionCount);
    return 0;
}