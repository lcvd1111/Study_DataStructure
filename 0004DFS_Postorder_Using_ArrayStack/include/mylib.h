#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PRINTF( x , ... ) printf("[%s, %d]" x , __func__, __LINE__, ##__VA_ARGS__)

#define STACK_MAX 30

//DATA TYPE DEFINITIONS
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

typedef enum _LAST_ACTION {
	TRIED_LEFT,
	TRIED_RIGHT,
	TRIED_NOTHING,
} LAST_ACTION;

typedef struct _STACK_DATA {
	BINTREE_NODE *dataAddress;
	LAST_ACTION dataAction;
} STACK_DATA;

typedef struct _STACK {
	STACK_DATA *stack_Array[STACK_MAX];
	int32_t end;
} STACK;

//FUNCTION DECLARATIONS
STACK *Push(STACK *, BINTREE_NODE *, LAST_ACTION, int *);
STACK *Pop(STACK *, STACK_DATA *, int *);
STACK *EmptyStack(STACK *);
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, int);
int PostOrder(BINTREE_NODE *);
int EmptyBintree(BINTREE_NODE *);
#endif
