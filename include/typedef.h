#pragma once

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
    int elementCount = -1;
    std::size_t elementSize = -1;
    int* shape = nullptr;
    void* data = nullptr;
} NPARR;
