#include "common.h"

int main(void)
{
	int err;
	if (err=UnitTest_MinHeap()){
		printf("Unit Test for Min Heap: Fail.\n");
		printf("Err code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Min Heap: Success.\n");
	
	return 0;
}
