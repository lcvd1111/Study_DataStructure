#include "mylib.h"
#include "test.h"

int main(int argc, char **argv)
{
	int err = 0;

	if (err=UnitTest_Stack()){
		printf("Unit Test for Stack: Fail.\n");
		printf("Err code: %d\n", err);
		return -1;
	}
	printf("Unit Test for Stack: Success.\n");

	if (err=UnitTest_Insert()){
		printf("Unit Test for Insert: Fail.\n");
		printf("Err code: %d\n", err);
		return -2;
	}
	printf("Unit Test for Insert: Success.\n");
	
	if (err=UnitTest_Search()){
		printf("Unit Test for Search: Fail.\n");
		printf("Err code: %d\n", err);
		return -3;
	}
	printf("Unit Test for Search: Success.\n");
	
	if (err=UnitTest_Delete()){
		printf("Unit Test for Delete: Fail.\n");
		printf("Err code: %d\n", err);
		return -4;
	}
	printf("Unit Test for Delete: Success.\n");

	return 0;
}
