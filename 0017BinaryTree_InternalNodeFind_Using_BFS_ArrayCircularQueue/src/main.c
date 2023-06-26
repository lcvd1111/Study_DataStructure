#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;
	if (err = UnitTest_ChildMake()){
		printf("Unit Test for Binary Tree Make: Failed.\n");
		printf("Err Code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Binary Tree Make: Success.\n");

	if (err = UnitTest_Queue()){
		printf("Unit Test for Queue: Failed.\n");
		printf("Err Code: %d\n", err);
		return -2;
	}
	printf("Unit Test for Queue: Success.\n");
	
	if (err = UnitTest_BFS()){
		printf("Unit Test for Finding Internal Nodes using BFS: Failed.\n");
		printf("Err Code: %d\n", err);
		return -3;
	}
	printf("Unit Test for BFS: Success.\n");

	return 0;
}
