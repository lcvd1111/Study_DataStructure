#include <stdio.h>
#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int ret = 0;
	if ((ret=UnitTest_Stack()) !=0){
		printf("Unit Test failed. Err=%d\n", ret);
		return -1;
	}
	printf("Unit test for stack: Success.\n");

	if ((ret=UnitTest_HeightFind_DFS()) !=0){
		printf("Unit Test failed. Err=%d\n", ret);
		return -2;
	}
	printf("Unit test for Finding Height of Binary tree using DFS: Success.\n");

	return 0;
}
