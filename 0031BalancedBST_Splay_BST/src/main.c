#include "common.h"

int main(void)
{
	int err = 0;
	if (err=UnitTest_Deque()){
		printf("Unit Test for Deque failed. err: %d\n", err);
		return -1;
	}
	printf("Unit Test for Deque success.\n");

	return 0;
}
