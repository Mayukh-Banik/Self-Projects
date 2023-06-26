#ifndef _FUNCTIONS_
#define _FUNCTIONS_

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

bool isMultiplyingValid(int* s1, int* s2, int d1, int d2);

#endif