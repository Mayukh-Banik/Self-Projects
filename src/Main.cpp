#include "includes.h"
#include "classes.h"
#include "npFuncDef.cpp"
#include "functions.h"

int main(int argc, char* argv[])
{
    TEST_EYE_ALL_VALUES_ZERO();
    TEST_IDENTITY();
    TEST_ONES();
    TEST_ZEROS();
    TEST_FILL();
    return 0;
}
