#include "typedef.h"
#pragma once
template <typename T>


// https://numpy.org/devdocs/reference/generated/numpy.empty.html
class NP 
{   
    public:
        struct NPARR* arr;

        NP();

        NP(NPARR* arr);

        NP(int elementCount, std::size_t elementSize, int* shape, void* data);

        /**
         * Return a new array of given shape and type, without initializing entries.
         * 
         * @param shape Terminated by 0, an allocated array in the heap by the use of 
         *  malloc, calloc, or realloc for the dimensions of the array
         * @param element Call (value) NULL for automatic typecasting of the data type 
         *  desired. Default will be double, if an int array is desired call with 
         *  (int) NULL
         * 
         * @return Array of uninitialized (arbitrary) data of the given shape and type. 
        */
        static NP* empty(int* shape, T element = (double) NULL);

        /**
         * Return a 2-D array with ones on the diagonal and zeros elsewhere.
         * 
        */
        static NP* eye(int N, int M, int K, T element = (double) NULL);

        /**
         * Returns a N by N square identity matrix
        */
        static NP* identity(int N, T element = (double) NULL);

        /**
         * Returns a shape matrix, filled with ones
        */
        static NP* ones(int* shape, T element = (double) NULL);

        /**
         * Returns a shape matrix, filled with zeros
        */
        static NP* zeros(int* shape, T element);

        /**
         * Returns a shape matrix with all values set to fillvalue
        */
        static NP* full(int* shape, T fillValue);

        /**
         * Use this to safely delete a NP object
        */
        static void deleteNP(NP* pointer);

        NP* copy();

        NP* multiply(const NP* obj1, const NP* obj2);
        


};