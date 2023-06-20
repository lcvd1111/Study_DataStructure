#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int ret = 0;
	if (ret=UnitTest_Queue()){
		printf("UnitTest for Queue: Failed. Error code: %d\n", ret);
		return -1;
	}
	printf("UnitTest for Queue: Success.\n");
	
	if (ret=UnitTest_BFS()){
		printf("UnitTest for Finding Height using BFS: Failed. Error code: %d\n", ret);
		return -1;
	}
	printf("UnitTest for Finding Height using BFS: Success.\n");
	
	return 0;
}
