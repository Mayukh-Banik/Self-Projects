#include "includes.h"
#include "classes.h"

template <typename T>

NP<T>::NP()
{
    this->arr = new NPARR;
}

template <typename T>

NP<T>::NP(NPARR* arr)
{
    this->arr = arr;
}

template <typename T>

NP<T>::NP(int elementCount, std::size_t elementSize, int* shape, void* data)
{
    this->arr = new NPARR;
    this->arr->elementCount = elementCount;
    this->arr->elementSize = elementSize;
    this->arr->shape = shape;
    this->arr->data = data;
}

template <typename T>

NP<T>* NP<T>::empty(int* shape, T element)
{
    if (shape == nullptr)
    {
        return nullptr;
    }
    int elementCount = 1;
    for (int count = 0; shape[count] != 0; count++)
    {
        elementCount = elementCount * shape[count];
    }
    NPARR* array = new NPARR;
    void* data = calloc(elementCount, sizeof(element));
    array->elementSize = sizeof(element);
    array->elementCount = elementCount;
    array->shape = shape;
    array->data = data;
    NP<T>* pointer = new NP<T>(array);
    return pointer;
}

template <typename T>

NP<T>* NP<T>::eye(int N, int M, int K, T element)
{
    if (N <= 0 || M < 0)
    {
        return nullptr;
    }
    int size = M == 0 ? N * N : N * M;
    NPARR* arr = new NPARR;
    void* data = malloc(sizeof(element) * size);
    arr->elementSize = sizeof(element);
    arr->elementCount = size;
    int* shape = (int*) malloc(sizeof(int) * 3);
    shape[0] = N;
    shape[1] = M == 0 ? N : M;
    shape[2] = 0;
    arr->shape = shape;
    arr->data = data;

    return nullptr;
}


template <typename T>

NP<T>* NP<T>::identity(int N, T element)
{
    if (N <= 0)
    {
        return nullptr;
    }
    T* eleSize = (T*) calloc(N * N, sizeof(element));
    for (int i = 0; i < N; i++)
    {
        eleSize[i + N * i] = 1.0;
    }
    NPARR* array = new NPARR;
    array->data = (void*) eleSize;
    array->elementSize = sizeof(element);
    array->elementCount = N * N;
    int* shape = (int*) malloc(sizeof(int) * 3);
    shape[0] = N;
    shape[1] = N;
    shape[2] = 0;
    array->shape = shape;
    NP<T>* pointer = new NP<T>(array);
    return pointer;
}