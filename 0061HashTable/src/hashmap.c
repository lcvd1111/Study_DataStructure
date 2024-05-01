#include "hashmap.h"

//Global Variables for binding object's method and global functions
static LINKED_LIST_NODE_METHOD gLinked_List_Node_Method = {
	.SetName = &LINKED_LIST_NODE_METHOD_SetName,
	.SetNumber = &LINKED_LIST_NODE_METHOD_SetNumber,
};
static LINKED_LIST_METHOD gLinked_List_Method = {
	.AddElement = &LINKED_LIST_METHOD_AddElement,
	.DeleteElement = &LINKED_LIST_METHOD_DeleteElement,
};
static HASHMAP_METHOD gHashMap_Method = {
	.Insert = &HASHMAP_METHOD_Insert,
	.Search = &HASHMAP_METHOD_Search,
	.Delete = &HASHMAP_METHOD_Delete,
	.Rehash = &HASHMAP_METHOD_Rehash,
	.Hash = &HASHMAP_METHOD_Hash,
	.Print = &HASHMAP_METHOD_Print,
};

//Function Definitions for Methods of LINKED_LIST_NODE type.
void LINKED_LIST_NODE_METHOD_CONSTRUCTOR(LINKED_LIST_NODE *this)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	//Initializing member variables
	memset(this->name, 0, NAME_LEN);
	this->number = 0;
	this->next = NULL;
	this->prev = NULL;

	//Binding Method Functions
	this->Method = &gLinked_List_Node_Method;

	return ;
}

void LINKED_LIST_NODE_METHOD_DESTRUCTOR(LINKED_LIST_NODE *this)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->next = NULL;
	this->prev = NULL;

	return ;
}

LINKED_LIST_NODE *LINKED_LIST_NODE_METHOD_SetName(LINKED_LIST_NODE *this, char *nameArg)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	memcpy(this->name, nameArg, NAME_LEN);

	return this;
}

LINKED_LIST_NODE *LINKED_LIST_NODE_METHOD_SetNumber(LINKED_LIST_NODE *this, int numberArg)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	this->number = numberArg;

	return this;
}

//Function Definitions for Methods of LINKED_LIST type.
void LINKED_LIST_METHOD_CONSTRUCTOR(LINKED_LIST *this)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	//Initializing the member variables
	this->begin = NULL;
	this->end = NULL;
	this->size = 0;

	//Binding method functions
	this->Method = &gLinked_List_Method;

	return ;
}

void LINKED_LIST_METHOD_DESTRUCTOR(LINKED_LIST *this)
{
	LINKED_LIST_NODE *temp = NULL;

	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->size == 0){
		assert((this->begin == NULL) && (this->end == NULL));
		return ;
	}

	temp = this->begin;
	while(temp->next != NULL){
		temp = temp->next;
		free(temp->prev);
	}
	free(temp);

	return ;
}

LINKED_LIST *LINKED_LIST_METHOD_AddElement
(LINKED_LIST *this, char *nameArg, int numberArg)
{
	LINKED_LIST_NODE *temp = NULL;

	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the list is empty currently.
	if (this->size == 0){
		assert(this->begin == NULL && this->end == NULL);
		this->begin = this->end = (LINKED_LIST_NODE *)malloc(sizeof(LINKED_LIST_NODE));
		LINKED_LIST_NODE_METHOD_CONSTRUCTOR(this->begin);
		memcpy(this->begin->name, nameArg, NAME_LEN);
		this->begin->number = numberArg;
		this->size += 1;
		return this;
	}

	//When the list is not empty.
	temp = this->begin;
	while(temp->next != NULL){
		temp = temp->next;
	}
	assert(temp->next == NULL);
	temp->next = (LINKED_LIST_NODE *)malloc(sizeof(LINKED_LIST_NODE));
	LINKED_LIST_NODE_METHOD_CONSTRUCTOR(temp->next);
	temp->next->prev = temp;
	memcpy(temp->next->name, nameArg, NAME_LEN);
	temp->next->number = numberArg;
	this->size += 1;

	return this;
}

LINKED_LIST *LINKED_LIST_METHOD_DeleteElement
(LINKED_LIST *this, LINKED_LIST_NODE *nodeArg)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the nodeArg is a begin node of the linked list
	if (nodeArg->prev == NULL){
		//When the nodeArg is an only node in the linked list
		if (nodeArg->next == NULL){
			assert(this->size == 1);
			this->begin = this->end = NULL;
			goto FINISH;
		}
		this->begin = nodeArg->next;
		this->begin->prev = NULL;
		goto FINISH;
	}

	//When the nodeArg is a end node of the linked list
	if (nodeArg->next == NULL){
		this->end = nodeArg->prev;
		this->end->next = NULL;
		goto FINISH;
	}

	//When the nodeArg is neither begin node nor end node
	nodeArg->prev->next = nodeArg->next;
	nodeArg->next->prev = nodeArg->prev;
	goto FINISH;

FINISH:
	free(nodeArg);
	this->size -= 1;
	return this;
}

//Function Definitions for Methods of HASHMAP type.
void HASHMAP_METHOD_CONSTRUCTOR(HASHMAP *this)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	//Initializing the member variables
	this->tableSize = 100;
	this->elementSize = 0;
	this->collisionNum = 0;
	this->table = (LINKED_LIST *)malloc(sizeof(LINKED_LIST)*(this->tableSize));
	for (int i=0 ; i<this->tableSize ; i++){
		LINKED_LIST_METHOD_CONSTRUCTOR(this->table + i);
	}

	return ;
}

void HASHMAP_METHOD_DESTRUCTOR(HASHMAP *this)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	for (int i=0 ; i<this->tableSize ; i++){
		LINKED_LIST_METHOD_DESTRUCTOR(this->table + i);
	}
	free(this->table);
	this->table = NULL;

	return ;
}

HASHMAP *HASHMAP_METHOD_Insert(HASHMAP *this, char *nameArg, int numberArg)
{
	int index = 0;
	LINKED_LIST *list = NULL;
	LINKED_LIST_NODE *node = NULL;

	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	index = (*(this->Method->Hash))(this, nameArg);
	list = (this->table)+index;

	//When there is no any element in the found index
	if (list->size == 0){
		(*(list->Method->AddElement))(list, nameArg, numberArg);
		this->elementSize += 1;
		return this;
	}

	node = list->begin;
	while(node != NULL){
		if (strcmp(node->name, nameArg) == 0){
			//There is already an element with same key value(=name).
			return NULL;
		}
		node = node->next;
	}
	//Collision resolving using chaining
	list->end->next = (LINKED_LIST_NODE *)malloc(sizeof(LINKED_LIST_NODE));
	LINKED_LIST_NODE_METHOD_CONSTRUCTOR(list->end->next);
	list->end->next->prev = list->end;
	list->end = list->end->next;
	list->size += 1;
	memcpy(list->end->name, nameArg, NAME_LEN);
	list->end->number = numberArg;

	this->elementSize += 1;
	this->collisionNum += 1;


	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 
	//Implement Rehashing!!!!! 

	return this;
}


HASHMAP *HASHMAP_METHOD_Search(HASHMAP *this, char *nameArg, LINKED_LIST_NODE **destArg)
{
	int index = 0;
	LINKED_LIST *list = NULL;
	LINKED_LIST_NODE *node = NULL;

	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	index = (*(this->Method->Hash))(this, nameArg);
	list = (this->table) + index;
	if (list->size == 0){
		//There is no element with given key values.
		return NULL;
	}

	node = list->begin;
	while(node != NULL){
		if (strcmp(node->name, nameArg) == 0){
			//Search Success!
			*destArg = node;
			return this;
		}
		node = node->next;
	}

	//There is no element with given key values.
	return NULL;
}


HASHMAP *HASHMAP_METHOD_Delete(HASHMAP *this, char *nameArg)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}
	
	return this;
}


HASHMAP *HASHMAP_METHOD_Rehash(HASHMAP *this)
{
	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}
	
	return this;
}


int HASHMAP_METHOD_Hash(HASHMAP *this, char *nameArg)
{
	int ret = 0;
	unsigned int buffer = 0;
	int rep = 0;

	//Error Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return -1;
	}

	rep = NAME_LEN/(sizeof(unsigned int));
	for (int i=0 ; i<rep ; i++){
		buffer = *(((unsigned int *)nameArg)+i);
		ret += buffer % (this->tableSize);
		ret = ret % (this->tableSize);
	}
	
	return ret;
}

void HASHMAP_METHOD_Print(HASHMAP *this)
{
	//Error Handling
	if (this == NULL){
		return ;
	}

	return ;
}
