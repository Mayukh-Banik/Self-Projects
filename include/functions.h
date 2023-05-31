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
        with all values within set to 0
    
    @throws ENOMEM assuming the allocation request fails
*/
Array* empty(char* DataType, int numArgs, void* data);

// https://numpy.org/devdocs/reference/generated/numpy.empty.html