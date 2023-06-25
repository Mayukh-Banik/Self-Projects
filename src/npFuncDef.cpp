#include "includes.h"
#include "classes.h"
#include "functions.h"

template <typename T>

void NP<T>::deleteNP(NP* pointer)
{
    free(pointer->arr->data);
    free(pointer->arr->shape);
    delete(pointer->arr);
    delete(pointer);
}

template <typename T>

NP<T>* NP<T>::copy()
{
    NPARR* temp = new NPARR;
    temp->elementCount = this->arr->elementCount;
    temp->elementSize = this->arr->elementSize;
    temp->dimensionCount = this->arr->dimensionCount;
    int* shape = (int*) calloc(1, sizeof(int) * (this->arr->dimensionCount + 1));
    if (shape == NULL)
    {
        delete(temp);
        free(shape);
        return nullptr;
    }
    memcpy(shape, this->arr->shape, sizeof(int) * (this->arr->dimensionCount + 1));
    temp->shape = shape;
    size_t size = (size_t) this->arr->elementCount * this->arr->elementSize; 
    void* data = malloc(size);
    memcpy(data, this->arr->data, size);
    NP<T>* x = new NP<T>(temp);
    return x;
}
/**
 * Element Wise Multiplication
*/
template <typename T>
template <typename X, typename Y>
NP<T>* NP<T>::multiply(const NP<X>* obj1, const NP<Y>* obj2)
{
    NPARR* one = obj1->arr;
    NPARR* two = obj2->arr;

    
    return nullptr;
}









































