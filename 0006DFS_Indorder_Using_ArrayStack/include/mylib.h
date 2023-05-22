#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PRINTF( x , ... ) printf("[FUN:%s LINE:%d]" x , __func__, __LINE__, ##__VA_ARGS__)

//Data type definitions
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

typedef struct _STACK {
	BINTREE_NODE **stackArray;
	int length;
	int end;
} STACK;

//Function Declarations
STACK *CreateStack(uint32_t);
STACK *Push(STACK *, BINTREE_NODE *, int *);
BINTREE_NODE *Pop(STACK *, int *);
STACK *CleanStack(STACK *);
int RemoveStack(STACK *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR,int, int);
BINTREE_NODE *CleanBintree(BINTREE_NODE *);
#endif
