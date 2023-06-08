#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>

typedef struct _BTREE_NODE {
	int data;
	struct _BTREE_NODE *left;
	struct _BTREE_NODE *right;
} BTREE_NODE;

typedef enum _CHILD_SELECTOR {
	LEFT,
	RIGHT,
	BOTH,
	NONE,
} CHILE_SELECTOR;

typedef struct _STACK_NODE {
	BTREE_NODE *nodeData;
	int l_sub_Level;
	int r_sub_Level;
	_STACK_NODE *next;
	_STACK_NODE *prev;
} STACK_NODE;

struct _STACK {
	STACK_NODE *begin;
	STACK_NODE *end;
} STACK;

#endif
