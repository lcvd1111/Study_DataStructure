#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x , ...) printf("[%s, %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define QUEUE_MAX 100

//Type Delcarations and Definitions
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum {
	NONE_CHILD,
	LEFT_CHILD,
	RIGHT_CHILD,
	BOTH_CHILD,
} CHILD_SELECTOR;

typedef struct {
	BINTREE_NODE *queueArray[QUEUE_MAX];
	int begin;
	int end;
} QUEUE;

//Function Declarations
QUEUE *CreateQueue(void);
QUEUE *Enqueue(QUEUE *, BINTREE_NODE *);
BINTREE_NODE *Dequeue(QUEUE *);
int DeleteQueue(QUEUE *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, int);
int CheckExternal(BINTREE_NODE *);
int FindInternal_BFS(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);
#endif
