#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Queue();
	
	if (err){
		printf("Unit Test for Queue: Fail.\n");
		printf("Error code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Queue: Success.\n");

	err = UnitTest_Graph();

	if (err){
		printf("Unit Test for Graph: Fail.\n");
		printf("Error code: %d\n", err);
		return -2;
	}
	printf("Unit Test for Graph: Success.\n");

	err = UnitTest_ShortestPath();

	if (err){
		printf("Unit Test for Finding Shortest Path using BFS: Fail.\n");
		printf("Error code: %d\n", err);
		return -3;
	}
	printf("Unit Test for Finding Shortest Path using BFS: Success.\n");

	return 0;
}
