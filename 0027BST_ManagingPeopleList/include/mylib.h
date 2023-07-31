#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 64
#define PRINTF( x , ... ) printf("[%s, %d]" x, __func__, __LINE__, ##__VA_ARGS__)

//Type Declarations and Definitions
typedef struct _BST_NODE {
	char name[STRING_LEN];
	char description[STRING_LEN];
	struct _BST_NODE *left, *right;
} BST_NODE;

typedef struct _BST {
	BST_NODE *root;
	int size;
} BST;

typedef struct _DEQUE_NODE {
	BST_NODE *data;
	struct _DEQUE_NODE *prev, *next;
} DEQUE_NODE;

typedef struct _DEQUE {
	DEQUE_NODE *begin;
	DEQUE_NODE *end;
} DEQUE;

//Function Declarations
BST *CreateBST(void);
BST *Search(BST *bstArg, char *searchArg, BST_NODE *outputStore);
BST *Add(BST *bstArg, char *addName, char *addDsc);
BST *Delete(BST *bstArg, char *deleteArg);
int CleanBST(BST *bstArg);
DEQUE *CreateDeque(void);
DEQUE *PushRight(DEQUE *dequeArg, BST_NODE *inputArg);
DEQUE *PopRight(DEQUE *dequeArg, BST_NODE **outputStore); //Stack Popping
DEQUE *PopLeft(DEQUE *dequeArg, BST_NODE **outputStore); //Queue Dequeuing
int CleanDeque(DEQUE *dequeArg);
DEQUE *InorderTraverse(BST *bstArg);
#endif
