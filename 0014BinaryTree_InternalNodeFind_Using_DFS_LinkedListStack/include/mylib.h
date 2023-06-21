#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[%s %d]" x, __func__, __LINE__, ##__VA_ARGS__)

//Type Definitions and Declarations
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
	void *header;
} BINTREE_NODE;

typedef struct _HEADER_DATA {
	char externalFlag;
	int left_Sub_Internal;
	int right_Sub_Internal;
} HEADER_DATA;

typedef enum _CHILD_SELECTOR {
	LEFT,
	RIGHT,
	BOTH,
	NONE,
} CHILD_SELECTOR;

typedef enum _ACTION {
	TRIED_LEFT,
	TRIED_RIGHT,
	TRIED_NONE,
} ACTION;

typedef struct _STACK_NODE {
	BINTREE_NODE *addressData;
	ACTION lastAction;
	struct _STACK_NODE *prev;
	struct _STACK_NODE *next;
} STACK_NODE;

typedef struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

//Function Declarations
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, int);
STACK *CreateStack(void);
STACK *Push(STACK *, BINTREE_NODE *, ACTION);
STACK *Pop(STACK *, STACK_NODE *);
STACK *EmptyStack(STACK *);
int DeleteStack(STACK *);
int CheckExternal(BINTREE_NODE *);
int FindSubInternalNodes(BINTREE_NODE *, CHILD_SELECTOR);
int FindInternalNodes(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);

#endif
