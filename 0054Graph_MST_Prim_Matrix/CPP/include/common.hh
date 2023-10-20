#ifndef __COMMON_HEADER__
#define __COMMON_HEADER__

#include <iostream>
#include <queue> //<vector>, <functional> is also automatically included by <queue>
#include <climits>

#define DEBUG std::cout<<"["<<__func__<<","<<__LINE__<<"]"
#define UNIT_TEST_FAIL DEBUG<<"Unit Test Failed."<<std::endl

#endif
