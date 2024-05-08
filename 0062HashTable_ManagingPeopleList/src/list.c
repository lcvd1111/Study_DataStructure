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
	this->prev = NULL;
	this->next = NULL;

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

	//Initializing the Member Variables
	this->begin = NULL;
	this->end = NULL;
	this->size = 0;

	//Binding the Method Functions
	this->Method = &gListMethod;

	return ;
}

void LIST_METHOD_DESTRUCTOR(LIST *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return;
	}

	//Making the list Empty.
	(this->Method->MakeEmpty)(this);

	return ;
}

int LIST_METHOD_GetSize(LIST *this)
{
	int ret = 0;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	ret = this->size;

	return ret;
}

int LIST_METHOD_IsEmpty(LIST *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Return True
	if (this->size == 0 && this->begin == NULL && this->end == NULL){
		return 1;
	}

	//Exception Handling
	if (this->size == 0 || this->begin == NULL || this->end == NULL){
		PRINTF_ERROR("ERROR: Something unexpected situation occured.\n");
		return -2;
	}

	//Return False
	return 0;
}

LIST *LIST_METHOD_AddElement(LIST *this, char *keyArg, char *dataArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (keyArg == NULL){
		PRINTF_ERROR("ERROR: 'keyArg' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (dataArg == NULL){
		PRINTF_ERROR("ERROR: 'dataArg' is NULL.\n");
		return NULL;
	}

	//When the list is empty.
	if (this->size == 0){
		assert(this->begin == NULL && this->end == NULL);
		this->begin = this->end = (LIST_NODE *)malloc(sizeof(LIST_NODE));
		LIST_NODE_METHOD_CONSTRUCTOR(this->begin);
		(this->begin->Method->SetKey)(this->begin, keyArg);
		(this->begin->Method->SetData)(this->begin, dataArg);
		this->size += 1;
		return this;
	}

	//When the list is not empty.
	this->end->next = (LIST_NODE *)malloc(sizeof(LIST_NODE));
	LIST_NODE_METHOD_CONSTRUCTOR(this->end->next);
	this->end->next->prev = this->end;
	this->end = this->end->next;
	(this->end->Method->SetKey)(this->end, keyArg);
	(this->end->Method->SetData)(this->end, dataArg);
	this->size += 1;

	return this;
}

LIST *LIST_METHOD_DeleteElement(LIST *this, LIST_NODE *removeArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (removeArg == NULL){
		PRINTF_ERROR("ERROR: 'removeArg' is NULL.\n");
		return NULL;
	}

	//When the list is empty.
	if (this->size == 0){
		assert(this->begin == NULL && this->end == NULL);
		return this;
	}

	//When the 'removeArg' is the first element of the list.
	if (removeArg->prev == NULL){
		assert(removeArg == this->begin);
		//When the 'removeArg' is the only element of the list.
		if (removeArg->next == NULL){
			assert(removeArg == this->end);
			assert(this->size == 1);
			LIST_NODE_METHOD_DESTRUCTOR(this->begin);
			free(this->begin);
			this->begin = this->end = NULL;
			this->size -= 1;
			return this;
		}

		this->begin = this->begin->next;
		LIST_NODE_METHOD_DESTRUCTOR(this->begin->prev);
		free(this->begin->prev);
		this->begin->prev = NULL;
		this->size -= 1;
		return this;
	}

	//When the 'removeArg' is the last element of the list.
	if (removeArg->next == NULL){
		assert(removeArg == this->end);
		this->end = this->end->prev;
		LIST_NODE_METHOD_DESTRUCTOR(this->end->next);
		free(this->end->next);
		this->end->next = NULL;
		this->size -= 1;
		return this;
	}

	//When the 'removeArg' is neither the begin node nor the end node.
	removeArg->prev->next = removeArg->next;
	removeArg->next->prev = removeArg->prev;
	LIST_NODE_METHOD_DESTRUCTOR(removeArg);
	free(removeArg);
	this->size -= 1;

	return this;
}

LIST *LIST_METHOD_MakeEmpty(LIST *this)
{
	int beforeSize = this->size;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the list is empty
	if (this->size == 0){
		assert(this->begin == NULL && this->end == NULL);
		return this;
	}

	//When the list is not empty
	for (int i=0 ; i<beforeSize ; i++){
		this->Method->DeleteElement(this, this->begin);
	}

	//Exception Handling
	assert(this->size == 0);
	assert(this->begin == NULL && this->end == NULL);

	return this;
}
