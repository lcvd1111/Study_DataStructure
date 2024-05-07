#include "list.h"

//Static-LifeTime, File-Scope, Internal-Linkage Variables for Binding every each object and Methods.
static LIST_NODE_METHOD gListNodeMethod = {
	.GetKey = &LIST_NODE_METHOD_GetKey,
	.GetData = &LIST_NODE_METHOD_GetData,
	.SetKey = &LIST_NODE_METHOD_SetKey,
	.SetData = &LIST_NODE_METHOD_SetData,
};

static LIST_METHOD gListMethod = {
	.GetSize = &LIST_METHOD_GetSize,
	.IsEmpty = &LIST_METHOD_IsEmpty,
	.AddElement = &LIST_METHOD_AddElement,
	.DeleteElement = &LIST_METHOD_DeleteElement,
	.MakeEmpty = &LIST_METHOD_MakeEmpty,
};

//Function Definitions for Method of 'LIST_NODE' type.
void LIST_NODE_METHOD_CONSTRUCTOR(LIST_NODE *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	//Initializing the member variables
	memset(this->key, 0, NAME_LEN);
	memset(this->data, 0, NAME_LEN);

	//Binding the Method Functions
	this->Method = &gListNodeMethod;
	
	return ;
}

void LIST_NODE_METHOD_DESTRUCTOR(LIST_NODE *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	return ;
}

int LIST_NODE_METHOD_GetKey(LIST_NODE *this, char *dst)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (dst){
		PRINTF_ERROR("ERROR: 'dst' is NULL.\n");
		return -2;
	}

	memcpy(dst, this->key, NAME_LEN);

	return 0;
}

int LIST_NODE_METHOD_GetData(LIST_NODE *this, char *dst)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (dst){
		PRINTF_ERROR("ERROR: 'dst' is NULL.\n");
		return -2;
	}

	memcpy(dst, this->data, DATA_LEN);

	return 0;
}

int LIST_NODE_METHOD_SetKey(LIST_NODE *this, char *nameArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (nameArg == NULL){
		PRINTF_ERROR("ERROR: nameArg is NULL.\n");
		return -2;
	}

	memcpy(this->key, nameArg, NAME_LEN);

	return 0;
}

int LIST_NODE_METHOD_SetData(LIST_NODE *this, char *dataArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (dataArg == NULL){
		PRINTF_ERROR("ERROR: 'dataArg' is NULL.\n");
		return -2;
	}

	memcpy(this->data, dataArg, DATA_LEN);

	return 0;
}

//Function Defitinions for Method of 'LIST' type.
void LIST_METHOD_CONSTRUCTOR(LIST *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return;
	}

	return ;
}

void LIST_METHOD_DESTRUCTOR(LIST *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return;
	}

	return ;
}

int LIST_METHOD_GetSize(LIST *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	return 0;
}

int LIST_METHOD_IsEmpty(LIST *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	return 0;
}

LIST *LIST_METHOD_AddElement(LIST *this, char *nameArg, char *dataArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	return this;
}

LIST *LIST_METHOD_DeleteElement(LIST *this, LIST_NODE *removeArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	return this;
}

LIST *LIST_METHOD_MakeEmpty(LIST *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	return this;
}
