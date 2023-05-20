#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "test.h"

#define UNIT_TEST_GO

BINTREE_NODE *MakeTree
(int, int, int, int, int, int, int, int, int, int);

int main(int argc, char **argv)
{
	BINTREE_NODE *root = NULL;
#ifdef UNIT_TEST_GO
	UnitTest();
#endif
	root = MakeTree(1,2,3,4,5,6,7,8,9,10);
	LevelOrder(root);
	return 0;
}

BINTREE_NODE *MakeTree
(int argA, int argB, int argC, int argD, int argE,
 int argF, int argG, int argH, int argI, int argJ)
{
	BINTREE_NODE *ret = NULL;
	ret = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	ret->data = argA;
	ret->left = NULL;
	ret->right = NULL;

	MakeChild(ret, BOTH, argB, argC);
	MakeChild(ret->left, BOTH, argD, argE);
	MakeChild(ret->right, BOTH, argF, argG);
	MakeChild(ret->left->right, LEFT, argH, argH);
	MakeChild(ret->right->left, RIGHT, argI, argI);
	MakeChild(ret->right->right, LEFT, argJ, argJ);

	return ret;
}
