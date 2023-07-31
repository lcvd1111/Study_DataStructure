#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTF( x , ... ) printf("[%s,%d]" x, __func__, __LINE__, ##__VA_ARGS__)

//Type Declarations and Definitions
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left, *right;
	char threadFlag;
} BINTREE_NODE;

typedef struct _DEQUE_NODE {
	BINTREE_NODE *addressData;
	struct _DEQUE_NODE *next, *prev;
} DEQUE_NODE;

typedef struct _DEQUE {
	DEQUE_NODE *begin, *end;
} DEQUE;

//Function Declarations
BINTREE_NODE *Insert(BINTREE_NODE *root, int data);
DEQUE *CreateDeque(void);
DEQUE *PushLeft(DEQUE *, BINTREE_NODE *);
BINTREE_NODE *PopLeft(DEQUE *);
DEQUE *PushRight(DEQUE *, BINTREE_NODE *);
BINTREE_NODE *PopRight(DEQUE *);
DEQUE *EmptyDeque(DEQUE *);
int DeleteDeque(DEQUE *);
BINTREE_NODE *InorderTraverse(BINTREE_NODE *root, DEQUE *outputDeque);
BINTREE_NODE *LevelorderTraverse(BINTREE_NODE *root, DEQUE *outputDeque);
BINTREE_NODE *CopyBintree(BINTREE_NODE *src);
BINTREE_NODE *FindInorderSuccessor(BINTREE_NODE *root, BINTREE_NODE *target);
BINTREE_NODE *MakeThreadedTree(BINTREE_NODE *src);
BINTREE_NODE *ThreadedTraverse(BINTREE_NODE *root, DEQUE *outputDeque);
int DeleteBintree(BINTREE_NODE *root);
int DeleteThreadedTree(BINTREE_NODE *root); 
#endif
