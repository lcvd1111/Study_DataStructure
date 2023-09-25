#include "common.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;

	if (err = UnitTest_Queue()){
		printf("Unit Test for Queue: Failed.\n");
		printf("Error Code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Queue: Success.\n");

	if (err = UnitTest_Graph()){
		printf("Unit Test for Graph: Failed.\n");
		printf("Error Code: %d\n", err);
		return -2;
	}
	printf("Unit Test for Graph: Success.\n");

	if (err = UnitTest_BFS_Undirected()){
		printf("Unit Test for BFS for Undirected Graph: Failed.\n");
		printf("Error Code: %d\n", err);
		return -3;
	} 
	printf("Unit Test for BFS for Undirected Graph: Success.\n");

	if (err = UnitTest_BFS_Directed()){
		printf("Unit Test for BFS for Directed Graph: Failed.\n");
		printf("Error Code: %d\n", err);
		return -4;
	}
	printf("Unit Test for BFS for Directed Graph: Success.\n");

	return 0;
}
