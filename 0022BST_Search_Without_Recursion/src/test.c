#include "test.h"

int UnitTest_MakeChild(void)
{
	BINTREE_NODE *testRoot = NULL;
	testRoot = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	testRoot->number = 1;
	strncpy(testRoot->name, "Joon", 32);
	MakeChild(testRoot, BOTH, 2, "Ellen", 3, "Kim");
	return 0;
}

int UnitTest_Search(void)
{
	return 0;
}
