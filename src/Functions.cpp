#include "includes.h"
#include "../include/functions.h"

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



