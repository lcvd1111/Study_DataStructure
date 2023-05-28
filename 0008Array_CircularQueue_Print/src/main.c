#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"
#include "interface.h"
#include "test.h"

int main(int arc, char **argv)
{
	int emptyErr;
	QUEUE *myQueue = NULL;

	
	myQueue = CreateQueue(9);
	
	EnQueue(myQueue, 1);
	EnQueue(myQueue, 2);
	EnQueue(myQueue, 3);
	EnQueue(myQueue, 4);
	EnQueue(myQueue, 5);
	EnQueue(myQueue, 6);
	
	DeQueue(myQueue, &emptyErr);		
	DeQueue(myQueue, &emptyErr);	
	DeQueue(myQueue, &emptyErr);	
	DeQueue(myQueue, &emptyErr);
	
	EnQueue(myQueue, 7);
	EnQueue(myQueue, 8);
	EnQueue(myQueue, 9);
	EnQueue(myQueue, 9);
	EnQueue(myQueue, 9);
	EnQueue(myQueue, 9);
	
	DeQueue(myQueue, &emptyErr);
	DeQueue(myQueue, &emptyErr);
	DeQueue(myQueue, &emptyErr);
	
	PrintQueue(myQueue);
	
	return 0;
}
