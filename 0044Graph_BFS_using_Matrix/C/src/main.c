#include <test.h>

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Queue();

	if (err){
		printf("Unit Test for Queue: Failed.\n");
		printf("Error code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Queue: Success.\n");

	err = UnitTest_Graph();
	if (err){
		printf("Unit Test for Graph: Failed.\n");
		printf("Error code: %d\n", err);
		return -2;
	}
	printf("Unit Test for Graph: Success.\n");

	err = UnitTest_BFS_Undirected();
	if (err){
		printf("Unit Test for BFS for Undirected graph: Failed.\n");
		printf("Error code: %d\n", err);
		return -3;
	}
	printf("Unit Test for BFS for Undirected graph: Success.\n");

	err = UnitTest_BFS_Directed();
	if (err){
		printf("Unit Test for BFS for Directed graph: Failed.\n");
		printf("Error code: %d\n", err);
		return -4;
	}
	printf("Unit Test for BFS for Directed graph: Success.\n");



	return 0;
}
