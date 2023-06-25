#include "includes.h"
#include "npFuncDef.cpp"
#include "NPConstructorDef.cpp"
#include "NPCreationRoutines.cpp"
#include "functions.h"
#include "classes.h"
#include "Functions.cpp"
#include <gtest/gtest.h>

// TEST(Eye, SquareEvenZero)
// {
//     NP<double>* arr = NP<double>::eye(5, 5, 0, (double) NULL);
//     int count = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         int x = 0;
//         for (int j = 0; j < 5; j++)
//         {
//             // ASSERT_EQ(((double*) arr->arr->data)[count++], 0);
//             x = x + (int) ((double*) arr->arr->data)[count++];
//         }
//         ASSERT_EQ(x, 1);
//     }
//     NP<double>::deleteNP(arr);
// }

// TEST(Empty, NDimension)
// {
//     int* s = shape(8, 3, 2, 6);
//     NP<char>* temp = NP<char>::empty(s, (double) NULL);
//     for (int i = 0; i < 8 * 3 * 2 * 6; i++)
//     {
//         ASSERT_EQ(((char*)temp->arr->data)[i], 0);
//     }
//     NP<char>::deleteNP(temp);
// }

// TEST(Identity, Hundred)
// {
//     int T = 100;
//     NP<double>* temp = NP<double>::identity(T);
//     for (int i = 0; i < T; i++) 
//     {
//         for (int j = 0; j < T; j++) 
//         {
//             if (i == j) 
//             {
//                 ASSERT_EQ(((double*) temp->arr->data)[T * i + i], 1);
//             } 
//             else 
//             {
//                 ASSERT_EQ(((double*) temp->arr->data)[T * j + i], 0);
//             }
//         }
//     }
//     NP<double>::deleteNP(temp);
// }

// TEST(Ones, TwoDimension)
// {
//     int* s = shape(5,3);
//     NP<double>* temp = NP<double>::ones(s, (double) NULL);
//     for (int i = 0; i < 15; i++)
//     {
//         ASSERT_EQ(((double*)temp->arr->data)[i], 1);
//     }
//     NP<double>::deleteNP(temp);
// }

// TEST(Zero, TwoDimension)
// {
//     int* s = shape(5, 3);
//     NP<double>* temp = NP<double>::zeros(s, (double) NULL);
//     for (int i = 0; i < 15; i++)
//     {
//         ASSERT_EQ(((double*)temp->arr->data)[i], 0);
//     }
//     NP<double>::deleteNP(temp);
// }

// TEST(Fill, IntThreeDimension)
// {
//     int* s = shape(4, 3, 5);
//     int FILL = 109;
//     NP<int>* temp = NP<int>::full(s, FILL);
//     for (int i = 0; i < 60; i++)
//     {
//         ASSERT_EQ(((int*) temp->arr->data)[i], FILL);
//     }
//     NP<int>::deleteNP(temp);
// }

// TEST(Shape, OneDimension)
// {
//     int* s = shape(2);
//     ASSERT_EQ(s[0], 2);
//     ASSERT_EQ(s[1], 0);
//     free(s);
// }

// TEST(Shape, TwoDimension)
// {
//     int* s = shape(2,2);
//     ASSERT_EQ(s[0], 2);
//     ASSERT_EQ(s[1], 2);
//     ASSERT_EQ(s[2], 0);
//     free(s);
// }

// TEST(Shape, NDimension)
// {
//     int* s = shape(1,2384,30,123,234,123);
//     int x = 0;
//     ASSERT_EQ(s[x++], 1);
//     ASSERT_EQ(s[x++], 2384);
//     ASSERT_EQ(s[x++], 30);
//     ASSERT_EQ(s[x++], 123);
//     ASSERT_EQ(s[x++], 234);
//     ASSERT_EQ(s[x++], 123);
//     ASSERT_EQ(s[x++], 0);
//     free(s);
// }

// TEST(Shape, None)
// {
//     ASSERT_EQ(shape(NULL), nullptr);
// }


bool checkArrays(int* X, int* Y, int D1, int D2) {
    int i = D1 - 1; // Index for array X
    int j = D2 - 1; // Index for array Y

    while (i >= 0 && j >= 0) 
    {
        if (X[i] == 1 || Y[j] == 1)
        {
            i--;
            j--;
            continue;
        }
        if (X[i] != Y[j]) 
        {
            return false; 
        }
        i--;
        j--;
    }

    return true; 
}


int main(int argc, char** argv)
{
    int* s = shape(NULL);
    free(s);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}