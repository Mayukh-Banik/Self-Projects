#include "typedef.h"

template <typename T>

class NP 
{   
    public:
        struct NPARR* arr;

        NP();

        NP(int elementCount, int elementSize, bool real, bool sign, int** shape, void* data);

        static NP* empty(int** shape, int elementSize);

        static NP* eye(int N, int M, int K, int elementSize);

        static NP* identity(int N, int elementSize);

        static NP* ones(int** shape, int elementSize);

        static NP* zeros(int** shape, int elementSize);

        static NP* full(int** shape, void* fillValue, int elementSize, NP* vals);
};