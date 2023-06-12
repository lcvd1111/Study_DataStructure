#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

#define PRINTF( x , ... ) printf("[FUNC:%s LINE:%d]" x, __func__, __LINE__, ##__VA_ARGS__);

//Type Declarations and Definitions
typedef struct _BTREE_NODE {
	int data;
	struct _BTREE_NODE *left;
	struct _BTREE_NODE *right;
	void *header;
} BTREE_NODE;

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

typedef enum _TRIED_ACTION {
	TRIED_LEFT,
	TRIED_RIGHT,
	NOTHING,
} TRIED_ACTION;

typedef struct _STACK_NODE {
	BTREE_NODE *nodeAddress;
	TRIED_ACTION lastTried;
	struct _STACK_NODE *next;
	struct _STACK_NODE *prev;
} STACK_NODE;

typedef struct _WRAPPED_NODE {
	BTREE_NODE *nodeAddress_W;
	TRIED_ACTION lastTried_W;
} WRAPPED_NODE;

typedef struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

//Function Declarations
BTREE_NODE *MakeChild(BTREE_NODE *, CHILD_SELECTOR, int , int );
STACK *CreateStack(void);
STACK *Push(STACK *, BTREE_NODE *, TRIED_ACTION);
WRAPPED_NODE *Pop(STACK *);
STACK *EmptyStack(STACK *);
int RemoveStack(STACK *);
int Calc_Subtree_Height(BTREE_NODE, CHILD_SELECTOR);
int Calc_Btree_Height_DFS(BTREE_NODE *root);
#endif
