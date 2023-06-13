//My Opinion: Don't do this shit unless you exploit the recursive function.
//Just use BFS instead.

#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	if (!UnitTest_Stack())
		printf("Unit Test for Stack: Success.\n");
	else
		return -1;

	if (!UnitTest_HeightFind())
		printf("Unit Test for Binary tree Height find: Success.\n");
	else 
		return -2;

	return 0;
}
