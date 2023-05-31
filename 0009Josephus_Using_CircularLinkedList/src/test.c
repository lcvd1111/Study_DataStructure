#include "test.h"

int UnitTest(void)
{
	if (Josephus(6,2) != 5){
		printf("Test case 1 failed.\n");
		return -1;
	}
	printf("Test case 1 passed.\n");
	
	if (Josephus(41,2) != 19){
		printf("Test case 2 failed.\n");
		return -1;
	}
	printf("Test case 2 passed.\n");
	
	if (Josephus(41,19) != 25){
		printf("Test case 3 failed.\n");
		return -1;
	}
	printf("Test case 3 passed.\n");
	
	if (Josephus(41,25) != 12){
		printf("Test case 4 failed.\n");
		return -1;
	}
	printf("Test case 4 passed.\n");
	
	if (Josephus(41,12) != 28){
		printf("Test case 5 failed.\n");
		return -1;
	}
	printf("Test case 5 passed.\n");
	
	if (Josephus(23,20) != 18){
		printf("Test case 6 failed.\n");
		return -1;
	}
	printf("Test case 6 passed.\n");
	
	if (Josephus(23,18) != 15){
		printf("Test case 7 failed.\n");
		return -1;
	}
	printf("Test case 7 passed.\n");

	if (Josephus(16,8) != 7){
		printf("Test case 8 failed.\n");
		return -1;
	}
	printf("Test case 8 passed.\n");

	return 0;
}
