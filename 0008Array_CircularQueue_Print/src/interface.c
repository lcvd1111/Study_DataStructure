#include "interface.h"

//Function Definitions
void ShowMenu(void)
{
}

int SelectMenu(void)
{
	return 0;
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
	return arg;
}

QUEUE *UserDequeue(QUEUE *arg)
{
	return arg;
}
