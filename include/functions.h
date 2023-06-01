#include "npArrayDef.h"

int saveToFileArrayFormat(Array* array, char* filepath);
Array* loadFromFile(char* filepath);
void inputStringHandler(char* input);

/*
    Numpy.empty() Implementation
    Return a new array of given shape and type, all data set to 0.

    @param DataType String of the data type to be used correct forms are:
        "double"; "long-double"; "long"; "int"; "float".
        Optional, May use NULL as a parameter, default value will be double
    @param numArgs Dimension Count that determines how to parse data
    @param data A caller allocated/deallocated array containing integers
        of the value of each dimension, so ((int*) data)[0] of a 2d-array
        will be the number of rows in the array

    @return An allocated array at least of size of all dimensions multiplied
        with all values within set to 0, this will have to be appended to 
        a predefined array to be appended, this only allocates the data to store
        the actual values
    
    @throws ENOMEM assuming the allocation request fails
*/
void* empty(char* DataType, int numArgs, void* data);

/*
    Return a 2-D array with ones on the diagonal and zeros elsewhere.

    @param N Number of rows
    @param M Number of columns (0 if N == M)
    @param DataType String for data type
    @param K Offset

    @return Pointer to allocated array that can store the data
*/
void* eye(int N, int M, char* DataType, int K);

void* identity(int N, char* DataType);

// https://numpy.org/devdocs/reference/generated/numpy.empty.html