#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[%s, %d]" x, __func__, __LINE__, ##__VA_ARGS__)

//Type Declarations and Definitions
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE ;

typedef enum {
	NONE,
	LEFT,
	RIGHT,
	BOTH,
} CHILD_SELECT;

typedef struct _STACK_NODE {
	BINTREE_NODE *addressData;
	struct _STACK_NODE *prev;
	struct _STACK_NODE *next;
} STACK_NODE; 

typedef struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

//Function Declarations
STACK *CreateStack(void);
STACK *Push(STACK *, BINTREE_NODE *);
BINTREE_NODE *Pop(STACK *);
STACK *EmptyStack(STACK *);
int DeleteStack(STACK *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECT, int, int);
BINTREE_NODE *MakeMirror_DFS(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);
#endif
