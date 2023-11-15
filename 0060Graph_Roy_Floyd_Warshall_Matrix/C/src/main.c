#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Graph();
	if (err){
		printf(COLOR_RED "Unit Test for Graph: FAIL.\n");
		printf(COLOR_RED "Error Code: %d\n", err);
		return -1;
	}
	printf(COLOR_GREEN "Unit Test for Graph: SUCCESS.\n");

	err = UnitTest_FloydWarshall();
	if (err){
		printf(COLOR_RED "Unit Test for Floyd-Warshall Algorithm: FAIL.\n");
		printf(COLOR_RED "Error Code: %d\n", err);
		return -2;
	}
	printf(COLOR_GREEN "Unit Test for Floyd-Warshall Algorithm: SUCCESS.\n");

    return 0;
}
