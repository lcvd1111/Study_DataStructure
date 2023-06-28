#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x, ... ) printf("[%s,%d]" x, __func__, __LINE__, ##__VA_ARGS__);

//Type Definitions and Declarations
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left, *right;
} BINTREE_NODE;

typedef enum {
	NONE,
	LEFT,
	RIGHT,
	BOTH
} CHILD_SELECT;

typedef struct _QUEUE_NODE {
	BINTREE_NODE *addressData;
	struct _QUEUE_NODE *prev, *next;
} QUEUE_NODE;

typedef struct {
	QUEUE_NODE *begin;
	QUEUE_NODE *end;
} QUEUE;

//Function Declarations
QUEUE *CreateQueue(void);
QUEUE *Enqueue(QUEUE *, BINTREE_NODE *);
BINTREE_NODE *Dequeue(QUEUE *);
QUEUE *EmptyQueue(QUEUE *);
int DeleteQueue(QUEUE *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECT, int, int);
BINTREE_NODE *MakeMirror_BFS(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);
#endif
