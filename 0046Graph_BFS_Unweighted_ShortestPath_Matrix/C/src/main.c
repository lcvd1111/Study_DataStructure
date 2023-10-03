#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Queue();
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

	err = UnitTest_ShortestPath_BFS();
	if (err){
		printf("Unit Test for Finding Shortest Path: Fail.\n");
		return -3;
	}
	printf("Unit Test for Finding Shortest Path: Success.\n");

	return 0;
}
