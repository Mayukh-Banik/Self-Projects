#include "functions.h"
#include "includeStatements.h"

void* empty(char* DataType, int numArgs, void* data)
{
    void* array = NULL;
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
        array = calloc(1, sizeof(double) * numberOfElements);
    }
    return array;
}

void* eye(int N, int M, char* DataType, int K)
{
    if (M < 0 || DataType == NULL || N <= 0)
    {
        return NULL;
    }
    void* array = NULL;
    {
        int* temp = malloc(sizeof(int));
        temp[0] = N * M;
        array = empty(DataType, 1, temp);
        free(temp);
    }
    int size = N < M ? M : N;
    for (int i = 0; i < size; i++) 
    {
        int index = i * size + i + K;
        if (index >= 0 && index < size * size) 
        {
            if (strcmp(DataType, "double") == 0)
            {
                ((double*) array)[index] = 1;
            }
            else if (strcmp(DataType, "long-double") == 0)
            {
                ((long double*) array)[index] = 1;
            }
            else if (strcmp(DataType, "long") == 0)
            {
                ((long*) array)[index] = 1;
            }
            else if (strcmp(DataType, "int") == 0)
            {
                ((int*) array)[index] = 1;
            }
            else if (strcmp(DataType, "float") == 0)
            {
                ((float*) array)[index] = 1;
            }
            else
            {
                ((double*) array)[index] = 1;
            }
        }
    } 
    return array;
}

void* identity(int N, char* DataType)
{
    void* array = NULL;
    if (strcmp(DataType, "double") == 0)
    {
        array = calloc(1, sizeof(double) * N * N);
        for (int i = 0; i < N; i++) 
        {
            ((double*)array)[i * N + i] = 1;
        }
    }
    else if (strcmp(DataType, "long-double") == 0)
    {
        array = calloc(1, sizeof(long double) * N * N);
        for (int i = 0; i < N; i++) 
        {
            ((long double*)array)[i * N + i] = 1;
        }
    }
    else if (strcmp(DataType, "long") == 0)
    {
        array = calloc(1, sizeof(long) * N * N);
        for (int i = 0; i < N; i++) 
        {
            ((long*)array)[i * N + i] = 1;
        }
    }
    else if (strcmp(DataType, "int") == 0)
    {
        array = calloc(1, sizeof(int) * N * N);
        for (int i = 0; i < N; i++) 
        {
            ((int*)array)[i * N + i] = 1;
        }
    }
    else if (strcmp(DataType, "float") == 0)
    {
        array = calloc(1, sizeof(float) * N * N);
        for (int i = 0; i < N; i++) 
        {
            ((float*)array)[i * N + i] = 1;
        }
    }
    else
    {
        array = calloc(1, sizeof(double) * N * N);
        for (int i = 0; i < N; i++) 
        {
            ((double*)array)[i * N + i] = 1;
        }
    }
    return array;
}

