#ifndef __MY_LIB_HEADER__
#define __MY_LIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINTF( x , ... ) printf("[%s, %d]" x, __func__, __LINE__, ##__VA_ARGS__)
#define NAME_MAX 16

//Type Declarations and Definitions
typedef struct _BINTREE_NODE {
	int number;
	char name[NAME_MAX];
	struct _BINTREE_NODE *left, *right;
} BINTREE_NODE;

typedef struct _STACK_NODE {
	BINTREE_NODE *data;
	struct _STACK_NODE *prev, *next;
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
BINTREE_NODE *Search(BINTREE_NODE *root, int key);
BINTREE_NODE *Insert(BINTREE_NODE *root, int keyArg, const char *keyStr);
BINTREE_NODE *Delete(BINTREE_NODE *root, int key);
int DeleteBintree(BINTREE_NODE *root);
#endif
