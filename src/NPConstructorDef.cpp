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