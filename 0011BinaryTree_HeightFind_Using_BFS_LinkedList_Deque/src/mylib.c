#include "mylib.h"

/*    Function Definitions    */
BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector, int leftArg, int rightArg)
{
	if (parent==NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch (selector) {
	case NONE:
		break;
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->left == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}

		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;

		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->right == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}

		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;

		break;
	case BOTH:
		if (!((parent->left == NULL) && (parent->right == NULL))){
			PRINTF("ERROR: parent already has a child or children.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->left == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}

		parent->left->data = leftArg;
		parent->left->left = NULL;
		parent->left->right = NULL;

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->right == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}

		parent->right->data = rightArg;
		parent->right->left = NULL;
		parent->right->right = NULL;

		break;
	default:
		PRINTF("ERROR: Wrong selector value.\n");
		return NULL;
		break;
	}
	
	return parent;
}

int CleanBintree(BINTREE_NODE *root)
{
	return 0;
}

DEQUE *CreateDeque(void)
{
	DEQUE *ret = NULL;
	ret = (DEQUE *)malloc(sizeof(DEQUE));
	ret->begin = NULL;
	ret->end = NULL;

	return ret;
}

DEQUE *PushLeft(DEQUE *dequeArg, BINTREE_NODE *binArg, int levelArg)
{
	//When Deque is empty.
	if ((dequeArg->begin == NULL) && (dequeArg->end == NULL)){
		dequeArg->begin = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));
		
		if(dequeArg->begin == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}

		dequeArg->end = dequeArg->begin;
		dequeArg->begin->addressData = binArg;
		dequeArg->begin->levelData = levelArg;
		dequeArg->begin->prev = NULL;
		dequeArg->begin->next = NULL;
		
		return dequeArg;
	}

	//When Deque is not empty.
	dequeArg->begin->prev = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));
	if (dequeArg->begin->prev == NULL){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	dequeArg->begin->prev->addressData = binArg;
	dequeArg->begin->prev->levelData = levelArg;
	dequeArg->begin->prev->prev = NULL;
	dequeArg->begin->prev->next = dequeArg->begin;
	dequeArg->begin = dequeArg->begin->prev;
	
	return dequeArg;
}

DEQUE *PopLeft(DEQUE *dequeArg, WRAPPED_NODE *poppedData)
{

	if (poppedData == NULL){
		PRINTF("ERROR: poppedData argument is NULL.\n");
		return NULL;
	}

	//When Deque is empty.
	if ((dequeArg->begin == NULL) && (dequeArg->end == NULL)){
		return NULL;
	}

	poppedData->bintreeNode = dequeArg->begin->addressData;
	poppedData->level = dequeArg->begin->levelData;
	
	//When Deque has single element.
	if (dequeArg->begin == dequeArg->end)
	{
		free(dequeArg->begin);
		dequeArg->begin = NULL;
		dequeArg->end = NULL;
		return dequeArg;
	}

	//When Deque has more than one element.
	dequeArg->begin = dequeArg->begin->next;
	free(dequeArg->begin->prev);
	dequeArg->begin->prev = NULL;

	return dequeArg;
}

DEQUE *PushRight(DEQUE *dequeArg, BINTREE_NODE *binArg, int levelArg)
{
	//When Deque is empty.
	if ((dequeArg->begin == NULL) && (dequeArg->end == NULL)){
		dequeArg->begin = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));
		
		if(dequeArg->begin == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}

		dequeArg->end = dequeArg->begin;
		dequeArg->begin->addressData = binArg;
		dequeArg->begin->levelData = levelArg;
		dequeArg->begin->prev = NULL;
		dequeArg->begin->next = NULL;
		
		return dequeArg;
	}

	//When Deque is not empty.
	dequeArg->end->next = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));

	if (dequeArg->end->next == NULL){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	dequeArg->end->next->addressData = binArg;
	dequeArg->end->next->levelData = levelArg;
	dequeArg->end->next->prev = dequeArg->end;
	dequeArg->end->next->next = NULL;
	dequeArg->end = dequeArg->end->next;

	return dequeArg;
}

DEQUE *PopRight(DEQUE *dequeArg, WRAPPED_NODE *poppedData)
{
	if (poppedData == NULL){
		PRINTF("ERROR: poppedData argument is NULL.\n");
		return NULL;
	}

	//When deque is empty.
	if ((dequeArg->begin==NULL) && (dequeArg->end==NULL)){
		return NULL;
	}

	poppedData->bintreeNode = dequeArg->end->addressData;
	poppedData->level = dequeArg->end->levelData;

	//When deque has one element.
	if (dequeArg->begin == dequeArg->end){
		free(dequeArg->begin);
		dequeArg->begin = NULL;
		dequeArg->end = NULL;
		return dequeArg;
	}

	//When deque has more than one element.
	dequeArg->end = dequeArg->end->prev;
	free(dequeArg->end->next);
	dequeArg->end->next = NULL;

	return dequeArg;
}

int LevelFindBFS(BINTREE_NODE *root)
{
	int ret = 0;
	return ret;
}

DEQUE *CleanDeque(DEQUE *dequeArg)
{
	WRAPPED_NODE dummy;
	
	while(PopLeft(dequeArg, &dummy) != NULL)
		;

	if (!((dequeArg->begin==NULL) && (dequeArg->end==NULL))){
		PRINTF("ERROR: Deque is still not empty.\n");
		return NULL;
	}

	return dequeArg;
}

int DeleteDeque(DEQUE *dequeArg)
{
	if(dequeArg != CleanDeque(dequeArg)){
		PRINTF("ERROR: CleanDeque( ) failed.\n");
		return -1;
	}

	free(dequeArg);

	return 0;
}
