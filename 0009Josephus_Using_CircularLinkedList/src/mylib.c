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
	temp->next->number = data;
	temp->next->next = listArg->begin; 
	temp->next->prev = temp;	
	listArg->begin->prev = temp->next;

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

	ret->current = NULL;
	ret->begin = NULL;

	for (int i=0 ; i<lengTh ; i++){
		Add_List(ret, i+1);
	}


	return ret;
}

CIRCULAR_LIST *Kill_Current(CIRCULAR_LIST *listArg)
{
	CIRCULAR_LIST_NODE *temp = NULL;

	if (listArg->current == NULL){
		PRINTF("ERROR: Current variable is NULL.\n");
		return NULL;
	}

	if ((listArg->begin == listArg->begin->next) && (listArg->begin == listArg->begin->prev)){
		//When there is only an one single element in list.
		free(listArg->begin);
		listArg->begin = NULL;
		return listArg;
	}

	if (listArg->current == listArg->begin){
		listArg->begin = listArg->begin->next;
		listArg->begin->prev = listArg->begin->prev->prev;
		listArg->begin->prev->next = listArg->begin;
		free(listArg->current);
		listArg->current = listArg->begin;
		return listArg;
	}

	temp = listArg->current;

	listArg->current = listArg->current->next;
	listArg->current->prev = listArg->current->prev->prev;
	listArg->current->prev->next = listArg->current;

	free(temp);

	return listArg;
}

int Destroy_List(CIRCULAR_LIST *listArg)
{
	if (listArg->begin == NULL){
		//When the list is empty.
		free(listArg);
		return 0;
	}

	listArg->current = listArg->begin;

	while(1){
		if (Kill_Current(listArg) != NULL){
			break;
		}
	}
	free(listArg);

	return 0;
}

CIRCULAR_LIST *Move_One(CIRCULAR_LIST *listArg)
{
	if (listArg->current == NULL){
		listArg->current = listArg->begin;
		return listArg;
	}
	listArg->current = listArg->current->next;

	return listArg;

}

CIRCULAR_LIST *Move_Several(CIRCULAR_LIST *listArg, int num)
{
	for (int i=0; i<num ; i++){
		Move_One(listArg);
	}

	return listArg;
}

int Josephus(int n, int k)
{
	int ret;
	CIRCULAR_LIST *peopleList = NULL;
	peopleList = Create_List(n);
	peopleList->current = peopleList->begin;

	while(1){	
		Move_Several(peopleList,k-1);
		Kill_Current(peopleList);

		if
			((peopleList->current == peopleList->current->next)
			&&
			(peopleList->current == peopleList->current->prev))
		{
			break;
		}
	}	

	ret = peopleList->current->number;

	Destroy_List(peopleList);
	
	return ret;
}
