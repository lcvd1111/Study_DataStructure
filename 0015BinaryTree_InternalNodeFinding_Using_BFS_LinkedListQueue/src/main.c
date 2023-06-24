#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err=0;
	if (err = UnitTest_Queue()){
		PRINTF("Fail Code: %d.\n", err);
		return -1;
	}
	PRINTF("Unit Test for Queue: Success.\n");

	if (err = UnitTest_BFS()){
		PRINTF("Fail Code: %d.\n", err);
		return -1;
	}
	PRINTF("Unit Test for Finding the number of internal nodes: Success.\n");

	return 0;
}
