#include "mylib.h"

//Fucntion Definitions
CIRCULAR_LIST *Add_List(CIRCULAR_LIST *listArg, int data)
{
	CIRCULAR_LIST_NODE *temp = NULL;

	if (listArg->begin == NULL){
		//When the list is empty.
		listArg->begin = (CIRCULAR_LIST_NODE *)malloc(sizeof(CIRCULAR_LIST_NODE));
		listArg->begin->number = data;
		listArg->begin->next = listArg->begin;
		listArg->begin->prev = listArg->begin;
		return listArg;
	}

	temp = listArg->begin->prev;

	temp->next = (CIRCULAR_LIST_NODE *)malloc(sizeof(CIRCULAR_LIST_NODE));
	temp->next->next = listArg->begin; 
	temp->next->prev = temp;
	temp->next->number = data;

	return listArg;
}

CIRCULAR_LIST *Create_List(int lengTh)
{
	CIRCULAR_LIST *ret = NULL;

	if (lengTh < 1){
		PRINTF("ERROR: Wrong length value.\n");
		return NULL;
	}

	ret = (CIRCULAR_LIST *)malloc(sizeof(CIRCULAR_LIST));
	if (ret == NULL){
		PRINTF("ERROR: malloc() failed.\n");
		return NULL;
	}

	for (int i=0 ; i<lengTh ; i++){
		Add_List(ret, i+1);
	}

	ret->current = ret->begin;

	return ret;
}

CIRCULAR_LIST *Kill_Current(CIRCULAR_LIST *listArg)
{
	if (listArg->current == NULL){
		PRINTF("ERROR: Current variable is NULL.\n");
		return NULL;
	}

	if ((listArg->begin == listArg->begin->next) && (listArg->begin == listArg->current)){
		//When there is only an one single element in list.
		free(listArg->begin);
		listArg->begin = NULL;
		return listArg;
	}

	if (listArg->begin == listArg->current){
		listArg->begin = listArg->begin->next;
		listArg->begin->prev = listArg->begin->prev->prev;
		free(listArg->current);
		listArg->current = listArg->begin;
		return listArg;
	}

	listArg->current = listArg->current->next;
	listArg->current->prev = listArg->current->prev->prev;
	free(listArg->current->prev);
	return listArg;
}

int Destroy_List(CIRCULAR_LIST *listArg)
{
	if (listArg->begin == NULL){
		//When the list is empty.
		free(listArg);
		return 0;
	}

	return 0;
}

CIRCULAR_LIST *Move_One(CIRCULAR_LIST *);
CIRCULAR_LIST *Move_Several(CIRCULAR_LIST *, int );
int Josephus(int n, int k);
