#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "interface.h"
#include "test.h"

//#define UNIT_TEST_GO


int main(int arc, char **argv)
{
	QUEUE *myQueue = NULL;
	myQueue = CreateQueue(QUEUE_LEN);
	int seLector = 0;

#ifdef UNIT_TEST_GO
	int ret = 0;
	if (ret = UnitTest()){
		printf("Unit Test Error. Error Code: %d.\n", ret);
		return -1;
	}
	printf("Unit Test Success.\n");
#endif

	while(1){
		ShowMenu();
		seLector = SelectMenu();
		switch(seLector){
		case 1:
			UserEnqueue(myQueue);
			break;
		case 2:
			UserDequeue(myQueue);
			break;
		case 3:
			CleanQueue(myQueue);
			PrintQueue(myQueue);
			break;
		case 4:
			PrintQueue(myQueue);
			break;
		default:
			printf("Wrong Select. Input an rigth number Pleasoe.\n");
			break;
		}
	}
	return 0;
}
