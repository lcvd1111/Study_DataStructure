#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[%s, %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define NAME_MAX 16

/*--- Type Declarations and Definitions ---*/
typedef struct _BINTREE_NODE {
	int number;
	char name[NAME_MAX];
	struct _BINTREE_NODE *left, *right;
} BINTREE_NODE;

typedef enum {
	NONE,
	LEFT,
	RIGHT,
	BOTH,
} CHILD_SELECT;

typedef struct _STACK_NODE {
	BINTREE_NODE *data;
	struct _STACK_NODE *prev, *next;
} STACK_NODE; 
//Stack is needed because of inorder traversal for deleting BST.
//It is not needed for BST's Insertion operation at all.

typedef struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

/*--- Function Declarations ---*/
BINTREE_NODE *Insert(BINTREE_NODE *, int, const char *);
STACK *CreateStack(void);
STACK *Push(STACK *, BINTREE_NODE *);
BINTREE_NODE *Pop(STACK *);
STACK *EmptyStack(STACK *);
int DeleteStack(STACK *);
int DeleteBintree(BINTREE_NODE *);

#endif
