#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTF( x , ... ) printf("[%s %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define NAME_MAX 32

//Type Declarations and Definitions
typedef struct _BINTREE_NODE {
	int number;
	char name[NAME_MAX];
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum {
	NONE,
	LEFT,
	RIGHT,
	BOTH
} CHILD_SELECTOR;

typedef struct _STACK_NODE {
	BINTREE_NODE *data;
	struct _STACK_NODE *prev;
	struct _STACK_NODE *next;
} STACK_NODE;

typedef struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

//Function Definitions
STACK *CreateStack(void);
STACK *Push(STACK *, BINTREE_NODE *);
BINTREE_NODE *Pop(STACK *);
BINTREE_NODE *Peek(STACK *);
STACK *EmptyStack(STACK *stackArg);
int DeleteStack(STACK *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, const char *, int, const char *);
BINTREE_NODE *SearchBST(BINTREE_NODE *root, int);
int DeleteBintree(BINTREE_NODE *root);
#endif
