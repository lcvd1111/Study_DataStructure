#ifndef __UNION_FIND_HEADER__
#define __UNION_FIND_HEADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _UNION_FIND UNION_FIND;

struct _UNION_FIND {
	int *predecessorVector;
	int *sizeVector;
	int entireSize;

	//Method Functions
	UNION_FIND *(*Create)(UNION_FIND *, int);
	UNION_FIND *(*Destroy)(UNION_FIND *);
	UNION_FIND *(*Unite)(UNION_FIND *, int, int);
	int (*Find)(UNION_FIND *, int);
	int (*Size)(UNION_FIND *, int);
	int (*EntireSize)(UNION_FIND *);
	int (*Same)(UNION_FIND *, int, int);
};

//Function Declarations
void UNION_FIND_CONSTRUCTOR(UNION_FIND *);
void UNION_FIND_DESTRUCTOR(UNION_FIND *);
UNION_FIND *UNION_FIND_METHOD_Create(UNION_FIND *, int);
UNION_FIND *UNION_FIND_METHOD_Destroy(UNION_FIND *);
UNION_FIND *UNION_FIND_METHOD_Unite(UNION_FIND *, int, int);
int UNION_FIND_METHOD_Find(UNION_FIND *, int);
int UNION_FIND_METHOD_Size(UNION_FIND *, int);
int UNION_FIND_METHOD_EntireSize(UNION_FIND *);
int UNION_FIND_METHOD_Same(UNION_FIND *, int, int);

#endif
