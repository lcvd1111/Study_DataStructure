//My Opinion: Don't do this shit unless recursive method is used.
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

	return 0;
}
