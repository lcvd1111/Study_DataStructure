#ifndef __LIB_STACK_HEADER__
#define __LIB_STACK_HEADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _STACK_NODE STACK_NODE;
typedef struct _STACK STACK;

struct _STACK_NODE {
	void *data;
	STACK_NODE *next, *prev;
};

struct _STACK {
	STACK_NODE *begin, *end;

	//Methods
	STACK *(*Push)(STACK *this, void *inputArg);
	STACK *(*Pop)(STACK *this, void **outputStorage);
	int (*Empty)(STACK *this);
	STACK *(*Clear)(STACK *this);
};

void STACK_CONSTRUCTOR(STACK *);
void STACK_DESTRUCTOR(STACK *);
STACK *STACK_METHOD_Push(STACK *this, void *inputArg);
STACK *STACK_METHOD_Pop(STACK *this, void **outputStore);
int STACK_METHOD_Empty(STACK *this);
STACK *STACK_METHOD_Clear(STACK *this);

#endif
