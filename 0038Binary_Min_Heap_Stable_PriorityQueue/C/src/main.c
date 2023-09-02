#include "common.h"

int main(int argc, char **argv)
{
	int err = 0;
	if (err=UnitTest_MinHeapStablePriorityQueue()){
		printf("Unit Test for Min Heap stable Priority Queue: Failed.\n");
		printf("Error code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Min Heap stable Priority Queue: Success.\n");
	return 0;
}
