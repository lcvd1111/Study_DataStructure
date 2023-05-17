#include <stdio.h>
#include <stdlib.h>
#include "../include/mylib.h"

int UnitTest(void);

int main(int argc, char **argv)
{
	if (UnitTest()){
		PRINTF("UNIT TEST ERROR.\n");
		return -1;
	}

	return 0;
}

int UnitTest(void)
{
		int ret = 0;
		return ret;
}
