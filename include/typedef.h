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
    int elementSize = -1;
    bool real = false;
    bool sign = false;
    int** shape = nullptr;
    void* data = nullptr;
} NPARR;
