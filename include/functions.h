void TEST_EMPTY_ALL_VALUES_ZERO();
void TEST_IDENTITY();
void TEST_ONES();
void TEST_ZEROS();
void TEST_FILL();
void TEST_SHAPE();
void TEST_EYE_STANDARD();

template <typename... Things>

/**
 * If only one value is given, it 
 * is assumed that there will be a 1 for the 
 * next value
*/
extern int* shape(Things... things);

extern bool isMultiplyingValid(int* s1, int* s2, int d1, int d2);