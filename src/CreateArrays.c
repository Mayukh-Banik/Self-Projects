#include "functions.h"
#include "includeStatements.h"

Array* empty(char* DataType, int numArgs, void* data)
{
    Array* array = NULL;
    int numberOfElements = 1;
    for (int i = 0; i < numArgs; i++)
    {
        numberOfElements = numberOfElements * ((int*) data)[i];
    }
    if (strcmp(DataType, "double") == 0)
    {
        array = calloc(1, sizeof(double) * numberOfElements);
    }
    else if (strcmp(DataType, "long-double") == 0)
    {
        array = calloc(1, sizeof(long double) * numberOfElements);
    }
    else if (strcmp(DataType, "long") == 0)
    {
        array = calloc(1, sizeof(long) * numberOfElements);
    }
    else if (strcmp(DataType, "int") == 0)
    {
        array = calloc(1, sizeof(int) * numberOfElements);
    }
    else if (strcmp(DataType, "float") == 0)
    {
        array = calloc(1, sizeof(float) * numberOfElements);
    }
    else
    {
        errno = EINVAL;
    }
    return array;
}