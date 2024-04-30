#include "test.h"

int main(void)
{
	int err = 0;

	printf(COLOR_BLACK "Unit Test for Linked List: " COLOR_BLACK);
	if (err = UnitTest_LinkedList()){
		printf(COLOR_RED "FAIL\n" COLOR_BLACK);
		printf("Error Code: %d\n", err);
		return -1;
	}
	printf(COLOR_GREEN "SUCCESS\n" COLOR_BLACK);

	printf(COLOR_BLACK "Unit Test for HashMap: " COLOR_BLACK);
	printf(COLOR_BLACK "Unit Test for Linked List: " COLOR_BLACK);
	if (err = UnitTest_HashMap()){
		printf(COLOR_RED "FAIL\n" COLOR_BLACK);
		printf("Error Code: %d\n", err);
		return -2;
	}
	printf(COLOR_GREEN "SUCCESS\n" COLOR_BLACK);

	return 0;
}
