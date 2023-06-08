#include "includes.h"
#include "npFuncDef.cpp"
#include "functions.h"
#include "classes.h"

void TEST_EYE_ALL_VALUES_ZERO()
{
    int* shape = (int*) malloc(sizeof(int) * 5);
    shape[0] = 8;
    shape[1] = 3;
    shape[2] = 2;
    shape[3] = 6;
    shape[4] = 0;
    NP<char>* temp = NP<char>::empty(shape, (double) NULL);
    for (int i = 0; i < 8 * 3 * 2 * 6; i++)
    {
        if (((char*)temp->arr->data)[i] != 0)
        {
            std::cout << "Error" <<std::endl;
            return;
        }
    }
    NP<char>::deleteNP(temp);
}

void TEST_IDENTITY()
{
    
}