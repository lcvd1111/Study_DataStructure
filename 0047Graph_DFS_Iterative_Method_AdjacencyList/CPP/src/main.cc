#include "test.hh"

int main(int argc, char **argv)
{
	int err = 0;
	
	err = UnitTest_Graph();
	if (err){
		printf("Unit Test for graph: Failed.\n");
		printf("Error Code: %d\n", err);
		return -1;
	}
	printf("Unit Test for graph: Success.\n");

	err = UnitTest_DFS_1_Undirected();
	if (err){
		printf("Unit Test for DFS_1 of undirected graph: Failed.\n");
		printf("Error Code: %d\n", err);
		return -2;
	}
	printf("Unit Test for DFS_1 of undirected graph: Success.\n");

	err = UnitTest_DFS_1_Directed();
	if (err){
		printf("Unit Test for DFS_1 of directed graph: Failed.\n");
		printf("Error Code: %d\n", err);
		return -3;
	}
	printf("Unit Test for DFS_1 of directed graph: Success.\n");

	err = UnitTest_DFS_2_Undirected();
	if (err){
		printf("Unit Test for DFS_2 of undirected graph: Failed.\n");
		printf("Error Code: %d\n", err);
		return -4;
	}
	printf("Unit Test for DFS_2 of undirected graph: Success.\n");

	err = UnitTest_DFS_2_Directed();
	if (err){
		printf("Unit Test for DFS_2 of directed graph: Failed.\n");
		printf("Error Code: %d\n", err);
		return -5;
	}
	printf("Unit Test for DFS_2 of directed graph: Success.\n");

	return 0;
}
