#include "includes.h"
#include "npFuncDef.cpp"
#include "functions.h"
#include "classes.h"

void TEST_EYE_ALL_VALUES_ZERO()
{
    return;
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
            std::cout << "TEST_EYE_ALL_VALUES_ZERO Error" <<std::endl;
            NP<char>::deleteNP(temp);
            return;
        }
    }
    NP<char>::deleteNP(temp);
}

void TEST_IDENTITY()
{
    int T = 100;
    NP<double>* temp = NP<double>::identity(T, (double) NULL);
    for (int i = 0; i < T; i++) 
    {
        for (int j = 0; j < T; j++) 
        {
            if (i == j) 
            {
                if (((double*) temp->arr->data)[T * i + i] != 1)
                {
                    std::cout << "TEST_IDENTITY Error" << std::endl;
                    NP<double>::deleteNP(temp);
                    return;             
                }
            } 
            else 
            {
                if (((double*) temp->arr->data)[T * j + i] != 0)
                {
                    std::cout << "TEST_IDENTITY Error" << std::endl;
                    NP<double>::deleteNP(temp);
                    return;             
                }
            }
        }
    }
    NP<double>::deleteNP(temp);
}

void TEST_ONES()
{
    int* shape = (int*) malloc(sizeof(int) * 3);
    shape[0] = 5;
    shape[1] = 3;
    shape[2] = 0;
    NP<double>* temp = NP<double>::ones(shape, (double) NULL);
    for (int i = 0; i < 15; i++)
    {
        if ( ((double*)temp->arr->data)[i] != 1)
        {
            std::cout << "TEST_ONES Error" << std::endl;
            NP<double>::deleteNP(temp);
            return;
        }
    }
    NP<double>::deleteNP(temp);
}

void TEST_ZEROS()
{
    int* shape = (int*) malloc(sizeof(int) * 3);
    shape[0] = 5;
    shape[1] = 3;
    shape[2] = 0;
    NP<double>* temp = NP<double>::zeros(shape, (double) NULL);
    for (int i = 0; i < 15; i++)
    {
        if ( ((double*)temp->arr->data)[i] != 0)
        {
            std::cout << "TEST_ZEROS Error" << std::endl;
            NP<double>::deleteNP(temp);
            return;
        }
    }
    NP<double>::deleteNP(temp);
}

void TEST_FILL()
{
    int* shape = (int*) malloc(sizeof(int) * 4);
    shape[0] = 4;
    shape[1] = 3;
    shape[2] = 5;
    shape[3] = 0;
    int FILL = 109;
    NP<int>* temp = NP<int>::full(shape, FILL);
    for (int i = 0; i < 60; i++)
    {
        if (((int*) temp->arr->data)[i] != FILL)
        {
            std::cout << "TEST_FILL ERROR" << std::endl;
            NP<int>::deleteNP(temp);
            return;
        }
    }
    NP<int>::deleteNP(temp);
}

