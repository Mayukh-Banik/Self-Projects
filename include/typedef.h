#ifndef _TYPEDEF_
#define _TYPEDEF_


// Content of typedef.h
typedef struct Node {
    void* object;
    void* next;
    void* prev;
} Node;

typedef struct ArrayList {
    int size;
    void** pointers;
} ArrayList;


typedef struct NPARR {
    int dimensionCount = -1;
    int elementCount = -1;
    std::size_t elementSize = -1;
    int* shape = nullptr;
    void* data = nullptr;
} NPARR;

#define MAX_DIMENSION_COUNT 64

#endif
