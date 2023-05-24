#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PRINTF( x , ... ) printf("[FUNC:%s LINE:%d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define QUEUE_MAX 40

//Data Type Definitions
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum _CHILD_SELECTOR {
	NONE,
	LEFT,
	RIGHT,
	BOTH,
} CHILD_SELECTOR;

typedef struct _QUEUE {
	BINTREE_NODE **queueArray;
	int begin;
	int end;
	uint32_t length;
} QUEUE;

//Function Declarations
QUEUE *CreateQueue(uint32_t);
QUEUE *Enqueue(QUEUE *, BINTREE_NODE *);
BINTREE_NODE *Dequeue(QUEUE *);
QUEUE *CleanQueue(QUEUE *);
int DeleteQueue(QUEUE *);

BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, int);
BINTREE_NODE *LevelOrder(BINTREE_NODE *);
int CleanBintree(BINTREE_NODE *);

#endif
