#include "includes.h"
#include "classes.h"
#include "functions.h"

template <typename T>

NP<T>* NP<T>::empty(int* shape, T element)
{
    if (shape == nullptr)
    {
        return nullptr;
    }
    int elementCount = 1, dimensionCount = 0;
    for (int count = 0; shape[count] != 0; count++)
    {
        elementCount = elementCount * shape[count];
        dimensionCount++;
    }
    NPARR* array = new NPARR;
    void* data = calloc(elementCount, sizeof(element));
    array->elementSize = sizeof(element);
    array->elementCount = elementCount;
    array->shape = shape;
    array->data = data;
    array->dimensionCount = dimensionCount;
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
    std::cout << "Size: " << size << std::endl;
    M = M == 0 ? N : M;
    NPARR* arr = new NPARR;
    T* data = (T*) calloc(1, sizeof(element) * size);
    int i = K;
    while (i < 0)
    {
        i = i + M + 1;
    }
    for ( ; i < size; i = i + M + 1)
    {
        data[i] = 1;
    }
    arr->elementSize = sizeof(element);
    arr->elementCount = size;
    arr->shape = shape(N, M == 0 ? N : M);
    arr->data = (void*) data;
    arr->dimensionCount = 2;
    NP<T>* a = new NP(arr);
    return a;
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

template <typename T>

NP<T>* NP<T>::ones(int* shape, T element)
{
    if (shape == nullptr || shape[0] == 0)
    {
        return nullptr;
    }
    NPARR* array = new NPARR;
    array->elementSize = sizeof(element);
    array->shape = shape;
    int i = 1, counter = 0;
    while (shape[counter] != 0 && counter < MAX_DIMENSION_COUNT) 
    {
        i = i * shape[counter];
        counter++;
    }
    array->elementCount = i;
    T* data = (T*) malloc(sizeof(element) * i);
    for (int count = 0; count < i; count++)
    {
        data[count] = 1;
    }
    array->data = data;
    NP<T>* pointer = new NP<T>(array);
    return pointer;

}

template <typename T>

NP<T>* NP<T>::zeros(int* shape, T element)
{
    if (shape == nullptr || shape[0] == 0)
    {
        return nullptr;
    }
    NPARR* array = new NPARR;
    array->elementSize = sizeof(element);
    array->shape = shape;
    int i = 1, counter = 0;
    while (shape[counter] != 0 && counter < MAX_DIMENSION_COUNT) 
    {
        i = i * shape[counter];
        counter++;
    }
    array->elementCount = i;
    T* data = (T*) calloc(1, sizeof(element) * i);
    array->data = data;
    NP<T>* pointer = new NP<T>(array);
    return pointer;
}

template <typename T>
                    
NP<T>* NP<T>::full(int* shape, T fillValue)
{
    if (shape == nullptr || shape[0] == 0)
    {
        return nullptr;
    }
    NPARR* array = new NPARR;
    array->elementSize = sizeof(fillValue);
    array->shape = shape;
    int i = 1, counter = 0;
    while (shape[counter] != 0) 
    {
        if (counter >= MAX_DIMENSION_COUNT)
        {
            break;
        }
        i = i * shape[counter];
        counter++;
    }
    array->elementCount = i;
    T* data = (T*) malloc(sizeof(fillValue) * i);
    for (int counter = 0; counter < array->elementCount; counter++)
    {
        data[counter] = fillValue;
    }
    array->data = data;
    NP<T>* pointer = new NP<T>(array);
    return pointer;
}
