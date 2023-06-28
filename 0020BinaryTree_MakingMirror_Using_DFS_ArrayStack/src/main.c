#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;

	if (err=UnitTest_MakeChild()){
		printf("Unit Test for MakeChild: Fail\n");
		printf("Err code: %d\n", err);
	}
	printf("Unit Test for MakeChild: Success\n");

	if (err=UnitTest_Stack()){
		printf("Unit Test for Stack: Fail\n");
		printf("Err code: %d\n", err);
	}
	printf("Unit Test for Stack: Success\n");

	if (err=UnitTest_MakeMirror()){
		printf("Unit Test for MakeMirror: Fail\n");
		printf("Err code: %d\n", err);
	}
	printf("Unit Test for MakeMirror: Success\n");

	return 0;
}
