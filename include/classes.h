#include "typedef.h"
#pragma once
template <typename T>

class NP 
{   
    public:
        struct NPARR* arr;

        NP();

        NP(NPARR* arr);

        NP(int elementCount, std::size_t elementSize, int* shape, void* data);

        static NP* empty(int* shape, T element);

        static NP* eye(int N, int M, int K, T element);

        static NP* identity(int N, T element);

        static NP* ones(int** shape, int elementSize);

        static NP* zeros(int** shape, int elementSize);

        static NP* full(int** shape, void* fillValue, int elementSize, NP* vals);

        static void deleteNP(NP* pointer)
        {
            free(pointer->arr->data);
            free(pointer->arr->shape);
            delete(pointer->arr);
            delete(pointer);
        }
};