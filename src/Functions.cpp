#include "includes.h"

/**
 * Given a string of integers, returns a heap allocated 
 * array of the variable ints passed through terminated 
 * by and int of value 0. Usage is for every function 
 * that calls for a 'shape' to have this called beforehand.
 * 
 * @param Things A string of comma separated ints to 
 *  represent shape of the desired array
 * 
 * @return Array Shape, pass as is to function calls
*/
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
    if (arr[0] == 0)
    {
        free(arr);
        arr = nullptr;
        return arr;
    }
    arr = (int*) realloc(arr, sizeof(int) * (a+1));
    arr[a] = 0;
    return arr;
}

/**
 * Returns a double value of e^X using std::pow
 * 
 * @param element Value to raise e to 
 * 
 * @return e^element
*/
template <typename T>

double exp(T element)
{
    const double e = 2.718281828459045;
    return std::pow(e, element);
}

bool isMultiplyingValid(int* X, int* Y, int D1, int D2) 
{
    int i = D1 - 1; // Index for array X
    int j = D2 - 1; // Index for array Y

    while (i >= 0 && j >= 0) 
    {
        if (X[i] == 1 || Y[j] == 1)
        {
            i--;
            j--;
            continue;
        }
        if (X[i] != Y[j]) 
        {
            return false; 
        }
        i--;
        j--;
    }

    return true; 
}






