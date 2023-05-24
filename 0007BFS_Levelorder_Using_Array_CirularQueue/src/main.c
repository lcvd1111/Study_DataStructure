#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "test.h"

int main(int argc, char **arv)
{
	int ret = 0;
	if (ret=UnitTest()){
		printf("Unit Test Errror code: %d.\n", ret);
		return -1;
	}
	printf("Unit Test Complete.\n");
	return 0;
}
