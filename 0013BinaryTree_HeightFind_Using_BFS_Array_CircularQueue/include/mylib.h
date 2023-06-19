#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x, ...) printf("[%s %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define QUEUE_MAX 100

//Type Delcarations and Definitions
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum _CHILD_SELECTOR {
	LEFT,
	RIGHT,
	BOTH,
	NONE,
} CHILD_SELECTOR;

typedef struct {
	BINTREE_NODE *addressData;
	int levelData;
} QUEUE_NODE;

typedef struct {
	QUEUE_NODE *queueArray;
	int begin;
	int end;
} QUEUE;

//Function Declarations
BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR, int l, int r);
QUEUE *CreateQueue(void);
QUEUE *Enqueue(QUEUE *, BINTREE_NODE *, int level);
QUEUE *Dequeue(QUEUE *, QUEUE_NODE *);
QUEUE *EmptyQueue(QUEUE *);
int DeleteQueue(QUEUE *);
int FindHeightBFS(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);
#endif
