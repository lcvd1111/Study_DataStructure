#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[%s, %d]" x , __func__, __LINE__, ##__VA_ARGS__)
#define STACK_MAX 100

//Type Declarations and Definitions
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
	void *header;
} BINTREE_NODE;

typedef struct _HEADER_DATA {
	int left_Sub_Height;
	int right_Sub_Height;
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
	TRIED_NOTHING,
} ACTION;

typedef struct _WRAPPED_NODE {
	BINTREE_NODE *addressData;
	ACTION lastTried;
} WRAPPED_NODE;

typedef struct _STACK {
	WRAPPED_NODE *stackArray;
	int end;
} STACK;

//Function Declarations
BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR, int l_arg, int r_arg);
STACK *CreateStack();
STACK *Push(STACK *, BINTREE_NODE *, ACTION);
STACK *Pop(STACK *, WRAPPED_NODE *);
STACK *EmptyStack(STACK *);
int DeleteStack(STACK *);
int FindHeight_DFS(BINTREE_NODE *root);
int FindSubHeight(BINTREE_NODE *parent, CHILD_SELECTOR);
int DeleteBintree(BINTREE_NODE *root);
#endif
