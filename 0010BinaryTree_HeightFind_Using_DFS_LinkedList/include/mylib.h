#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

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
	NONE,
} TRIED_ACTION;

typedef struct _STACK_NODE {
	BTREE_NODE *nodeAddress;
	TRIED_ACTION *LastTried;
	_STACK_NODE *next;
	_STACK_NODE *prev;
} STACK_NODE;

struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

BTREE_NODE *MakeChild(BTREE_NODE *, CHILD_SELECTOR, int Left, int Right);
STACK_NODE *Pop(STACK *);
STACK *Push(STACK *, BTREE_NODE *, TRIED_ACTION);
int Calc_Subtree_Height(BTREE_NODE, CHILD_SELECTOR);
int Calc_Btree_Height_DFS(BTREE_NODE *root);
#endif
