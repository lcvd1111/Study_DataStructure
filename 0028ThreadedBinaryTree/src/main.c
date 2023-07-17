#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;

	if (err = UnitTest_Deque()){
		printf("Unit Test for Deque: Failed.\n");
		printf("Err code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Deque: Success.\n");
	
	if (err = UnitTest_BST()){
		printf("Unit Test for BST Insertion: Failed.\n");
		printf("Err code: %d\n", err);
		return -2;
	}
	printf("Unit Test for BST Insertion: Success.\n");

	if (err = UnitTest_CopyBintree()){
		printf("Unit Test for Binary tree Copy: Failed.\n");
		return -3;
	}
	printf("Unit Test for Binary tree Copy: Success.\n");
	
	if (err = UnitTest_DFSandBFS()){
		printf("Unit Test for DFS and BFS: Failed.\n");
		printf("Err code: %d\n", err);
		return -4;
	}
	printf("Unit Test for DFS and BFS: Success.\n");
	
	if (err = UnitTest_CreateThreaded()){
		printf("Unit Test for Creating Threaded tree: Failed.\n");
		printf("Err code: %d\n", err);
		return -5;
	}
	printf("Unit Test for Creating Threaded tree: Success.\n");
	
	if (err = UnitTest_ThreadedTraverse()){
		printf("Unit Test for Threaded tree Traversing: Failed.\n");
		printf("Err code: %d\n", err);
		return -6;
	}
	printf("Unit Test for Threaded tree Traversing: Success.\n");
	
	return 0;
}

