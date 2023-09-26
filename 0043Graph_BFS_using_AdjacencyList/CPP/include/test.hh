#ifndef __TEST_HEADER__
#define __TEST_HEADER__

#include "common.hh"
#include "lib_graph.hh"

#define UNIT_TEST_FAIL DEBUG<<"Unit Test Failed.\n"<<std::endl

int UnitTest_Graph(void);
int UnitTest_BFS_Undirected(void);
int UnitTest_BFS_Directed(void);

#endif
