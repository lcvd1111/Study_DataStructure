#include "common.h"

int main(int argc, char **argv)
{
	int err = 0;
	if(err=UnitTest_Heap()){
		printf("UnitTest_Heap: Failed.\n");
		printf("err code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Heap: Success.\n");

	return 0;
}
