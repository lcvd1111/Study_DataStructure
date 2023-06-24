#ifndef __MYLIB_HEADER__

#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 100

#define PRINTF( x , ... ) printf("[%s %d]" x, __func__, __LINE__, ##__VA_ARGS__)
//Type Definitions and Delcarations
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
	void *header;
} BINTREE_NODE;

typedef struct {
	int externalFlag;
	int leftSubTree_Internal;
	int rightSubTree_Internal;
} HEADER_DATA;

typedef enum {
	NONE,
	LEFT,
	RIGHT,
	BOTH,
} CHILD_SELECTOR;

typedef enum {
	TRIED_NONE,
	TRIED_LEFT,
	TRIED_RIGHT,
} ACTION_SELECTOR;

typedef struct {
	BINTREE_NODE *addressData;
	ACTION_SELECTOR triedAction;
} STACK_NODE;

typedef struct {
	STACK_NODE stackArray[STACK_MAX];
	int end;
} STACK;


//Function Declarations
STACK *CreateStack(void);
STACK *Push(STACK *, BINTREE_NODE *, ACTION_SELECTOR);
int Pop(STACK *, STACK_NODE *);
int DeleteStack(STACK *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, int);
int CheckExternalNode(BINTREE_NODE *);
int UpdateInternalNode(BINTREE_NODE *, CHILD_SELECTOR);
int FindInternalNodes_DFS(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);
#endif
