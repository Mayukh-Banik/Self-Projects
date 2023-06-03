#include "includes.h"
#include "classes.h"

NP::NP()
{
    this->arr = new NPARR;
}

NP::NP(int elementCount, int elementSize, bool real, bool sign, int** shape, void* data)
{
    this->arr = new NPARR;
    this->arr->elementCount = elementCount;
    this->arr->elementSize = elementSize;
    this->arr->real = real;
    this->arr->sign = sign;
    this->arr->shape = shape;
    this->arr->data = data;
}

