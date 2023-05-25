#include <aio.h>
typedef struct array {
    char name[50];
    int dimensionCount;
    int* dimensionValue;
    ssize_t size;
    void* arr;
} Array;