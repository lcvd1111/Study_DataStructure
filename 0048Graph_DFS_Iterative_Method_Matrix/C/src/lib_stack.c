#include "lib_stack.h"

void STACK_CONSTRUCTOR(STACK *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return ;
	}

	this->begin = NULL;
	this->end = NULL;
	this->Push = &STACK_METHOD_Push;
	this->Pop = &STACK_METHOD_Pop;
	this->Empty = &STACK_METHOD_Empty;
	this->Clear = &STACK_METHOD_Clear;

	return ;
}

void STACK_DESTRUCTOR(STACK *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return ;
	}

	//When the stack is empty.
	if ((*this).Empty(this)){
		return ;
	}

	//When the stack is not empty.
	(*this).Clear(this);
	return ;
}

STACK *STACK_METHOD_Push(STACK *this, int inputArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the stack is full. -> omit.

	//When the stack is empty.
	if ((*this).Empty(this)){
		this->begin = (STACK_NODE *)malloc(sizeof(STACK_NODE));
		this->end = this->begin;
		this->end->data = inputArg;
		this->end->next = NULL;
		this->end->prev = NULL;
		return this;
	}

	//Ordinary cases
	////Exception Handling
	if (this->end->next != NULL){
		DEBUG("ERROR: Unexpected Situation occured.\n");
		return NULL;
	}

	this->end->next = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	this->end->next->prev = this->end;
	this->end->next->next = NULL;
	this->end->next->data = inputArg;
	this->end = this->end->next;

	return this;
}

STACK *STACK_METHOD_Pop(STACK *this, int *outputStore)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the stack is empty
	if ((*this).Empty(this)){
		return NULL;
	}

	*outputStore = this->end->data;

	//When the stack has only an element.
	if ((*this).begin == (*this).end){
		free(this->end);
		this->begin = NULL;
		this->end = NULL;
		return this;
	}

	//Ordinary cases.
	this->end = this->end->prev;
	free(this->end->next);
	this->end->next = NULL;

	return this;
}

int STACK_METHOD_Empty(STACK *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	if (this->begin == NULL && this->end == NULL){
		return 1;
	}

	return 0;
}

STACK *STACK_METHOD_Clear(STACK *this)
{
	int dummyBuffer = 0;

	while((*this).Empty(this) == 0){
		(*this).Pop(this, &dummyBuffer);
	}

	if ((*this).Empty(this) != 1){
		DEBUG("ERROR: Unexpected situation occured.\n");
		return NULL;
	}

	return this;
}
