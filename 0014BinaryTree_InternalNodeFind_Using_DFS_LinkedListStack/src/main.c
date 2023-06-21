#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err;
	if (err=UnitTest_Stack()){
		printf("Unit Test for Stack: FAIL. Error code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Stack: SUCCESS.\n");

	if (err=UnitTest_DFS()){
		printf("Unit Test for Finding Internal Nodes: FAIL. Error code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Finding Internal Nodes: SUCCESS.\n");

	return 0;
}
