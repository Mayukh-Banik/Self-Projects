#include <aio.h>
#define MAX_CHARACTER_BUFFER_LENGTH 50
typedef struct array {
    char name[MAX_CHARACTER_BUFFER_LENGTH];
    char type[MAX_CHARACTER_BUFFER_LENGTH];
    int dimensionCount;
    int* dimensionValue;
    size_t size;
    void* arr;
} Array;

typedef struct arrayList {
    Array* arr;
    Array* next;
    Array* prev;
} ArrayList;