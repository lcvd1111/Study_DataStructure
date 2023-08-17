#include "common.h"

int main(void)
{
	int err = 0;

	if (err=UnitTest_Deque()){
		printf("Unit Test for Deque failed. err: %d\n", err);
		return -1;
	}
	printf("Unit Test for Deque success.\n");

	if (err=UnitTest_BST()){
		printf("Unit Test for BST failed. err: %d\n", err);
		return -2;
	}
	printf("Unit Test for BST success.\n");

	if (err=UnitTest_SplayBST()){
		printf("Unit Test for SplayBST failed. err: %d\n", err);
		return -3;
	}
	printf("Unit Test for SplayBST success.\n");

	return 0;
}
