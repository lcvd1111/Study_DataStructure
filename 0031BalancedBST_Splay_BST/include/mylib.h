#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEQUE_MAX 256
#define PRINTF( x , ... ) printf("[%s %d]" x, __func__, __LINE__)	

//Type Declarations and Definitions
typedef struct _SPLAY_BST_NODE {
	int data;
	struct _SPLAY_BST_NODE *parent;
	struct _SPLAY_BST_NODE *left;
	struct _SPLAY_BST_NODE *right;
} SPLAY_BST_NODE;

typedef struct _SPLAY_BST {
	SPLAY_BST_NODE *root;
} SPLAY_BST;

typedef struct _CIRCULAR_DEQUE {
	SPLAY_BST_NODE *dequeArray[DEQUE_MAX];
	int begin;
	int end;
} CIRCULAR_DEQUE;

typedef CIRCULAR_DEQUE DEQUE;

//Function Declarations
////SPLAY BST Operations
SPLAY_BST *Create_SplayBST(void);
SPLAY_BST *Insert_SplayBST(SPLAY_BST *BST, int value);
SPLAY_BST_NODE *Search_SplayBST(SPLAY_BST *BST, int value);
SPLAY_BST *Delete_SplayBST(SPLAY_BST *BST, int value);
int Remove_SplayBST(SPLAY_BST *BST);

////Building Blocks for SPLAY BST Operations
SPLAY_BST_NODE *Insert_BST(SPLAY_BST *BST, int value);
SPLAY_BST_NODE *Search_BST(SPLAY_BST *BST, int value);
SPLAY_BST *Delete_BST(SPLAY_BST *BST, int value);
SPLAY_BST_NODE *RotateLeft(SPLAY_BST *BST, SPLAY_BST_NODE *node);
SPLAY_BST_NODE *RotateRight(SPLAY_BST *BST, SPLAY_BST_NODE *node);

////Circular Deque Operations
CIRCULAR_DEQUE *CreateDeque(void);
CIRCULAR_DEQUE *PushLeft(CIRCULAR_DEQUE *, SPLAY_BST_NODE *inputArg);
CIRCULAR_DEQUE *PopLeft(CIRCULAR_DEQUE *, SPLAY_BST_NODE **outputStore);
CIRCULAR_DEQUE *PushRight(CIRCULAR_DEQUE *, SPLAY_BST_NODE *inputArg);
CIRCULAR_DEQUE *PopRight(CIRCULAR_DEQUE *, SPLAY_BST_NODE **outputStore);
int RemoveDeque(CIRCULAR_DEQUE *);

#endif
