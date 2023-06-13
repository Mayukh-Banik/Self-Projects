#include "includes.h"

template <typename... Things>

int* shape(Things... things) 
{
    int* arr = (int*) malloc(sizeof(int));
    int a = 0;
    for(const int p : {things...}) 
    {
        arr = (int*) realloc(arr, sizeof(int) * (a+1));
        arr[a] = p;
        a++;
    }
    if (a == 1)
    {
        arr = (int*) realloc(arr, sizeof(int) * 3);
        arr[1] = 1;
        arr[2] = 0;
        return arr;
    }
    arr = (int*) realloc(arr, sizeof(int) * (a+1));
    arr[a] = 0;
    return arr;
}

template <typename T>

double exp(T element)
{
    const double e = 2.718281828459045;
    return std::pow(e, element);
}














