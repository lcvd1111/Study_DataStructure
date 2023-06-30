#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[%s, %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define STACK_MAX 100

//Type Declarations and Definitions
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left, *right;
} BINTREE_NODE;

typedef enum {
	NONE,
	LEFT,
	RIGHT,
	BOTH,
} CHILD_SELECT;

typedef enum {
	TRIED_NONE,
	TRIED_LEFT,
	TRIED_RIGHT,
} TRIED_ACTION;

typedef struct _STACK_NODE {
	BINTREE_NODE *addressData;
	TRIED_ACTION triedAction;
} STACK_NODE;

typedef struct _STACK {
	STACK_NODE stackArray[STACK_MAX];
	int end;
} STACK;

//Function Declarations
STACK *CreateStack(void);
STACK *Push(STACK *, BINTREE_NODE *, TRIED_ACTION);
STACK *Pop(STACK *, STACK_NODE *);
int DeleteStack(STACK *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECT, int, int);
BINTREE_NODE *MakeMirror(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);
#endif
