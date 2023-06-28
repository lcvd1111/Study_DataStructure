#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;

	if (err = UnitTest_MakeChild()){
		printf("Unit Test for MakeChild: Failed.\n");
		printf("Err code: %d\n", err);
		return -1;
	}
	printf("Unit Test for MakeChild: Success.\n");
	
	if (err = UnitTest_Queue()){
		printf("Unit Test for Queue: Failed.\n");
		printf("Err code: %d\n", err);
		return -2;
	}
	printf("Unit Test for Queue: Success.\n");
	
	if (err = UnitTest_MakeMirror()){
		PRINTF("Unit Test for MakeMirror: Failed.\n");
		PRINTF("Err code: %d\n", err);
		return -3;
	}
	printf("Unit Test for MakeMirror: Success.\n");

	return 0;
}
