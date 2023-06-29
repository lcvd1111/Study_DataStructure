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

typedef struct _STACK {
	BINTREE_NODE *stackArray[STACK_MAX];
	int end;
} STACK;

//Function Declarations
STACK *CreateStack(void);
STACK *Push(STACK *, BINTREE_NODE *);
BINTREE_NODE *Pop(STACK *);
int DeleteStack(STACK *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECT, int, int);
BINTREE_NODE *MakeMirror(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);
#endif
