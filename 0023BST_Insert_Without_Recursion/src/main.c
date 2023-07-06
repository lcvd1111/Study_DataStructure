#include "test.h"

int main(int argc, char **argv)
{
	int err=0;
	
	if(err=UnitTest_Stack()){
		printf("Unit test for Stack: Fail.\n");
		printf("Err Code: %d\n", err);
	}
	printf("Unit test for Stack: Success.\n");
		
	if(err=UnitTest_Insert()){
		printf("Unit test for Insert: Fail.\n");
		printf("Err Code: %d\n", err);
	}
	printf("Unit test for Insert: Success.\n");
	
	return 0;
}
