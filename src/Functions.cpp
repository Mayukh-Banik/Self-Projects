#include "includes.h"

int* shape(int a, ...)
{
    int* arr = (int*) malloc(sizeof(int));
    arr[0] = a;

    va_list args;
    va_start(args, a);

    int size = 1;

    // Retrieve and store the variable arguments
    int arg;
    while ((arg = va_arg(args, int)) != 0) 
    {
        size++;
        arr = (int*) realloc(arr, size * sizeof(int));
        arr[size - 1] = arg;
    }
    size++;
    arr = (int*) realloc(arr, size * sizeof(int));
    arr[size - 1] = 0;

    return arr;
}

template <typename T>

double exp(T element)
{
    const double e = 2.718281828459045;
    return std::pow(e, element);
}














