#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

//Type Declarations and Definitions
typedef struct _BINTREE_NODE {
	int number;
	char name[32];
	struct _BINTREE_NODE *left;
	struct _BINTREE_NODE *right;
} BINTREE_NODE;

typedef enum {
	NONE,
	LEFT,
	RIGHT,
	BOTH
} CHILD_SELECTOR;

//Function Definitions
BINTREE_NODE *MakeChild(BINTREE_NODE *, CHILD_SELECTOR, int, const char *, int, const char *);
int SearchBST(BINTREE_NODE *root);

#endif
