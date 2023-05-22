#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	STACK *myStack = NULL;
	BINTREE_NODE *root = NULL;

	UnitTest();
	
	myStack = CreateStack();
	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
	root->data = 1;
	MakeChild(root, BOTH, 2, 3);
	MakeChild(root->left, BOTH, 4, 5);
	MakeChild(root->right, BOTH, 6, 7);
	MakeChild(root->left->right, LEFT, 8, 8);
	MakeChild(root->right->left, RIGHT, 9, 9);
	MakeChild(root->right->right, LEFT, 10, 10);

	PreOrder(root);

	return 0;
}
