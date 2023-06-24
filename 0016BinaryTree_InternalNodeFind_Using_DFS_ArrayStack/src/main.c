#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;
	if(err = UnitTest_Stack()){
		printf("Unit Test for Stack failed. err: %d\n", err);
		return -1;
	}
	printf("Unit Test for Stack Success.\n");

	if(err = UnitTest_DFS()){
		printf("Unit Test for DFS failed. err: %d\n", err);
		return -2;
	}
	printf("Unit Test for DFS Success.\n");


	return 0;
}
