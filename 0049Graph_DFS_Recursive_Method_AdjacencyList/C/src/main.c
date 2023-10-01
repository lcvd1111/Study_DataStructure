#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;
	err = UnitTest_Graph();
	if (err){
		printf("Unit Test for Graph: Fail.\n");
		printf("Error Code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Graph: Success.\n");

	err = UnitTest_DFS_Undirected();
	if (err){
		printf("Unit Test for DFS of undirected Graph: Fail.\n");
		printf("Error Code: %d\n", err);
		return -2;
	}
	printf("Unit Test for DFS of undirected Graph: Success.\n");

	err = UnitTest_DFS_Directed();
	if (err){
		printf("Unit Test for DFS of directed Graph: Fail.\n");
		printf("Error Code: %d\n", err);
		return -3;
	}
	printf("Unit Test for DFS of directed Graph: Success.\n");

	return 0;
}
