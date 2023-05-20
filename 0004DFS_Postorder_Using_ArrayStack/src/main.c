#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	BINTREE_NODE *root = NULL;
	root = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));

	test();
	return 0;
}
