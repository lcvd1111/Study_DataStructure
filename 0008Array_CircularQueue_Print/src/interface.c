#include "interface.h"
#include <stdlib.h>

//Function Definitions
void ShowMenu(void)
{
	printf("    <MENU>\n"
			"1. Enqueue to Queue.\n"
			"2. Dequeue from Queue.\n"
			"3. Clean Queue.\n"
			"4. Print Queue.\n"
		  );
}

int SelectMenu(void)
{
	int selector;
	char inputString[12];
	printf("Select the menu: ");
	fgets(inputString, 12, stdin);

	selector = atoi(inputString);

	return selector;
}

void PrintQueue(QUEUE *arg)
{
	char *printingArray = NULL;
	printingArray = (char *)malloc(sizeof(char) * (arg->length));
	
	if (arg->begin==0 && arg->end ==-1){
		//when queue is empty.
		for (int i=0 ; i<(arg->length) ; i++)
			printingArray[i] = '*';
	}
	else if (arg->begin > arg->end){
		for (int i=0 ; i<=arg->end ; i++)
			printingArray[i] = (arg->queueArray)[i] + '0';
		for (int i=(arg->end)+1 ; i<arg->begin ; i++)
			printingArray[i] = '*';
		for (int i=(arg->begin) ; i<(arg->length) ; i++)
			printingArray[i] = (arg->queueArray)[i] + '0';
	}
	else if (arg->begin <= arg->end){
		for (int i=(arg->begin) ; i <= (arg->end) ; i++)
			printingArray[i] = (arg->queueArray)[i] + '0';
		
		for (int i=0 ; i<arg->begin ; i++)
			printingArray[i] = '*';
		
		for (int i=(arg->end)+1 ; i < arg->length ; i++)
			printingArray[i] = '*';
	}

	printf("\n        %c    %c\n\n", printingArray[0], printingArray[1]);
	printf("    %c           %c\n\n", printingArray[7], printingArray[2]);
	printf("    %c           %c\n\n", printingArray[6], printingArray[3]);
	printf("        %c    %c\n\n", printingArray[5], printingArray[4]);

	free(printingArray);

	return ;
}

QUEUE* UserEnqueue(QUEUE *arg)
{
	int inputtedVal = 0;
	char inputtedString[15] = {0,};

	printf("Input an element to enqueue(0,1,...,9): ");
	fgets(inputtedString, 15, stdin);
	inputtedVal = atoi(inputtedString);

	if (!((0<=inputtedVal)&&(inputtedVal<=9))){
		printf("Wrong Input. Please input only an integer from 0 to 9.\n");
		return NULL;
	}

	if(EnQueue(arg, inputtedVal) == NULL){
		printf("Queue is full now.\n");
		return NULL;
	}

	PrintQueue(arg);

	return arg;
}

QUEUE *UserDequeue(QUEUE *arg)
{
	int emptyFlag = 0;
	int dequeuedVal = 0;

	dequeuedVal = DeQueue(arg, &emptyFlag);
	
	if (emptyFlag ==1){
		printf("Queue is empty now.\n");
		return NULL;
	}

	printf("Dequeued Value: %d\n", dequeuedVal);

	PrintQueue(arg);

	return arg;
}
