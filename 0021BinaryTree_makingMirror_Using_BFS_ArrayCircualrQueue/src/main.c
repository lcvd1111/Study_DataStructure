#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;

	if (err=UnitTest_MakeChild()){
		printf("Unit Test for MakeChild: Fail.\n");
		printf("Err Code: %d\n", err);
	}
	printf("Unit Test for MakeChild: Success.\n");

	if (err=UnitTest_Queue()){
		printf("Unit Test for Queue: Fail.\n");
		printf("Err Code: %d\n", err);
	}
	printf("Unit Test for Queue: Success.\n");

	if (err=UnitTest_MakeMirror()){
		printf("Unit Test for Making Mirror: Fail.\n");
		printf("Err Code: %d\n", err);
	}
	printf("Unit Test for Making Mirror: Success.\n");
	
	return 0;
}
