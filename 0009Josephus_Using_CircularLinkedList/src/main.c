#include "mylib.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(UnitTest()!=0){
		return -1;
	}
	printf("Unit Test Success.\n");

	return 0;
}
