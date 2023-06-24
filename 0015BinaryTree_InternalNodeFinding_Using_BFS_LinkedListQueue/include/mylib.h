#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[%s %d]" x , __func__, __LINE__, ##__VA_ARGS__)

//TYPE DEFINITIONS, TYPE DECLARATIONS
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum {
	LEFT,
	RIGHT,
	BOTH,
	NONE,
} CHILD_SELECTOR;

typedef struct _QUEUE_NODE {
	BINTREE_NODE *addressData;
	struct _QUEUE_NODE *prev;
	struct _QUEUE_NODE *next;
} QUEUE_NODE;

typedef struct {
	QUEUE_NODE *begin;
	QUEUE_NODE *end;
} QUEUE;

//FUNCTION DECLARATIONS
QUEUE *CreateQueue(void);
QUEUE *Push(QUEUE *, BINTREE_NODE *);
QUEUE *Pop(QUEUE *, QUEUE_NODE *);
QUEUE *EmptyQueue(QUEUE *);
int DeleteQueue(QUEUE *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, int);
int CheckExternalNode(BINTREE_NODE *);
int FindInternalNodes(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);
#endif
