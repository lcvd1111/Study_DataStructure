#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define PRINTF( x, ...) printf("[%s, %d]" x, __func__, __LINE__, ##__VA_ARGS__)

/*    Type Declarations and Definitions    */
typedef struct _BINTREE_NODE {
	int data;
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef struct _WRAPPED_NODE {
	BINTREE_NODE *bintreeNode;
	int level;
} WRAPPED_NODE;

typedef enum _CHILD_SELECTOR {
	LEFT,
	RIGHT,
	BOTH,
	NONE,
} CHILD_SELECTOR;

typedef struct _DEQUE_NODE {
	BINTREE_NODE *addressData;
	int levelData;
	struct _DEQUE_NODE *prev;
	struct _DEQUE_NODE *next;
} DEQUE_NODE;

typedef struct _DEQUE {
	DEQUE_NODE *begin;
	DEQUE_NODE *end;
} DEQUE;

/*    Function Declarations    */
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, int);
int CleanBintree(BINTREE_NODE *);

DEQUE *CreateDeque(void);
DEQUE *PushLeft(DEQUE *, BINTREE_NODE *, int);
DEQUE *PopLeft(DEQUE *, WRAPPED_NODE *);
DEQUE *PushRight(DEQUE *, BINTREE_NODE *, int);
DEQUE *PopRight(DEQUE *, WRAPPED_NODE *);
DEQUE *CleanDeque(DEQUE *);
int DeleteDeque(DEQUE *);
int LevelFindBFS(BINTREE_NODE *);
int DeleteBintree(BINTREE_NODE *);

#endif
