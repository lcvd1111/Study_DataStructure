#include "common.h"

int main(int argc, char **argv)
{
	int err = 0;

	if (err=UnitTest_StableHeap()){
		printf("Unit Test for Stable Priority Queue using Binary Max Heap: Fail.\n");
		printf("Err code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Stable Priority Queue using Binary Max Heap: Success.\n");
	
	return 0;
}
