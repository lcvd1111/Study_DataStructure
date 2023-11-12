#include "common.h"
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
	printf(COLOR_GREEN "Unit Test for Heap: SUCCESS.\n");

	err = UnitTest_UnionFind();
	if (err){
		printf(COLOR_RED "Unit Test for Union-Find: FAIL.\n");
		printf(COLOR_RED "Error Code: %d\n", err);
		return -2;
	}
	printf(COLOR_GREEN "Unit Test for Union-Find: SUCCESS.\n");

	err = UnitTest_Graph();
	if (err){
		printf(COLOR_RED "Unit Test for Graph: FAIL.\n");
		printf(COLOR_RED "Error Code: %d\n", err);
		return -3;
	}
	printf(COLOR_GREEN "Unit Test for Graph: SUCCESS.\n");

	err = UnitTest_Kruskal();
	if (err){
		printf(COLOR_RED "Unit Test for Kruskal Algorithm: FAIL.\n");
		printf(COLOR_RED "Error Code: %d\n", err);
		return -4;
	}
	printf(COLOR_GREEN "Unit Test for Kruskal Algorithm: SUCCESS.\n");

	return 0;
}
