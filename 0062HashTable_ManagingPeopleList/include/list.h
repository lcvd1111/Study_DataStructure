#ifndef __LIST_HEADER__
#define __LIST_HEADER__

#include "common.h"

//Type Definitions and Declarations.
typedef struct _LIST_NODE LIST_NODE;
typedef struct _LIST_NODE_METHOD LIST_NODE_METHOD;
typedef struct _LIST LIST;
typedef struct _LIST_METHOD LIST_METHOD;

struct _LIST_NODE {
	//Member Variables
	char key[NAME_LEN];
	char data[DATA_LEN];

	//Member Functions
	LIST_NODE_METHOD *Method;
};

struct _LIST_NODE_METHOD {
	int (*GetKey)(LIST_NODE *this, char *dst);
	int (*GetData)(LIST_NODE *this, char *dst);
	int (*SetKey)(LIST_NODE *this, char *nameArg);
	int (*SetData)(LIST_NODE *this, char *dataArg);
};

struct _LIST {
	//Member Variables
	LIST_NODE *begin;
	LIST_NODE *end;
	int size;

	//Member Functions
	LIST_METHOD *Method;
};

struct _LIST_METHOD {
	int (*GetSize)(LIST *this);
	int (*IsEmpty)(LIST *this);
	LIST *(*AddElement)(LIST *this, char *nameArg, char *dataArg);
	LIST *(*DeleteElement)(LIST *this, LIST_NODE *removeArg);
	LIST *(*MakeEmpty)(LIST *this);
};

//Function Declarations for Method of 'LIST_NODE' type.
void LIST_NODE_METHOD_CONSTRUCTOR(LIST_NODE *this);
void LIST_NODE_METHOD_DESTRUCTOR(LIST_NODE *this);
int LIST_NODE_METHOD_GetKey(LIST_NODE *this, char *dst);
int LIST_NODE_METHOD_GetData(LIST_NODE *this, char *dst);
int LIST_NODE_METHOD_SetKey(LIST_NODE *this, char *nameArg);
int LIST_NODE_METHOD_SetData(LIST_NODE *this, char *dataArg);

//Function Declarations for Method of 'LIST' type.
void LIST_METHOD_CONSTRUCTOR(LIST *this); 
void LIST_METHOD_DESTRUCTOR(LIST *this); 
int LIST_METHOD_GetSize(LIST *this);
int LIST_METHOD_IsEmpty(LIST *this);
LIST *LIST_METHOD_AddElement(LIST *this, char *nameArg, char *dataArg);
LIST *LIST_METHOD_DeleteElement(LIST *this, LIST_NODE *removeArg);
LIST *LIST_METHOD_MakeEmpty(LIST *this);

#endif
