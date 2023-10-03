#ifndef __COMMON_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG( x , ... ) printf("[%s, %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define UNIT_TEST_FAIL DEBUG("Unit Test Failed.\n")

#endif
