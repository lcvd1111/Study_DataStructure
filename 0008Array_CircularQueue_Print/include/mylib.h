#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[FUNC:%s LINE:%d]" x , __func__, __LINE__, ##__VA_ARGS__)

//Data type definitions
typedef struct QUEUE {
	int *queueArray;
	int begin;
	int end;
	int length;
} QUEUE;

//Function Declarations
QUEUE *CreateQueue(int);
QUEUE *EnQueue(QUEUE*, int);
int DeQueue(QUEUE *, int *);
QUEUE *CleanQueue(QUEUE *);
int DeleteQueue(QUEUE *);

#endif
