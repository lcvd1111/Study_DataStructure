#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Heap();
	if (err){
		printf(COLOR_RED "Unit Test for Heap: FAIL.\n");
		printf(COLOR_RED "Error Code: %d\n", err);
		return -1;
	}
	printf(COLOR_BLUE "Unit Test for Heap: SUCCESS.\n");

	err = UnitTest_Graph();
	if (err){
		printf(COLOR_RED "Unit Test for Graph: FAIL.\n");
		printf(COLOR_RED "Error Code: %d\n", err);
		return -2;
	}
	printf(COLOR_BLUE "Unit Test for Graph: SUCCESS.\n");

	err = UnitTest_Dijkstra();
	if (err){
		printf(COLOR_RED "Unit Test for Dijkstra Algorithm: FAIL.\n");
		printf(COLOR_RED "Error Code: %d\n", err);
		return -3;
	}
	printf(COLOR_BLUE "Unit Test for Dijkstra Algorithm: SUCCESS.\n");

	return 0;
} 
