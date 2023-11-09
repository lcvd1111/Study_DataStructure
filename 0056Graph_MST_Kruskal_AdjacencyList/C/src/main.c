#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;

	err = UnitTest_UnionFind();
	if (err){
		printf(COLOR_RED "Unit Test for UnionFind: FAIL.\n" COLOR_BLACK);
		printf(COLOR_RED "Error Code: %d\n" COLOR_BLACK, err);
		return -1;
	}
	printf(COLOR_GREEN "Unit Test for UnionFind: SUCCESS.\n" COLOR_BLACK);

	err = UnitTest_Heap();
	if (err){
		printf(COLOR_RED "Unit Test for Heap: FAIL.\n" COLOR_BLACK);
		printf(COLOR_RED "Error Code: %d\n" COLOR_BLACK, err);
		return -1;
	}
	printf(COLOR_GREEN "Unit Test for Heap: SUCCESS.\n" COLOR_BLACK);

	err = UnitTest_Graph();
	if (err){
		printf(COLOR_RED "Unit Test for Graph: FAIL.\n" COLOR_BLACK);
		printf(COLOR_RED "Error Code: %d\n" COLOR_BLACK, err);
		return -1;
	}
	printf(COLOR_GREEN "Unit Test for Graph: SUCCESS.\n" COLOR_BLACK);

	err = UnitTest_Kruskal();
	if (err){
		printf(COLOR_RED "Unit Test for Kruskal Algorithm: FAIL.\n" COLOR_BLACK);
		printf(COLOR_RED "Error Code: %d\n" COLOR_BLACK, err);
		return -1;
	}
	printf(COLOR_GREEN "Unit Test for Kruskal Algorithm: SUCCESS.\n" COLOR_BLACK);

	return 0;
}
