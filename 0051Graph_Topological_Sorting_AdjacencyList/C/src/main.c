#include "common.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = UnitTest_Queue();
	if (err){
		printf("Unit Test for Queue: Fail.\n");
		return -1;
	}
	printf("Unit Test for Queue: Success.\n");

	err = UnitTest_Graph();
	if (err){
		printf("Unit Test for Graph: Fail.\n");
		return -2;
	}
	printf("Unit Test for Graph: Success.\n");

	err = UnitTest_TopologicalSorting();
	if (err){
		printf("Unit Test for Topological Sorting: Fail.\n");
		return -3;
	}
	printf("Unit Test for Topological Sorting: Success.\n");

	return 0;
}
