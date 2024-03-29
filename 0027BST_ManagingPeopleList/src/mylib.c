#include "mylib.h"

//Function Definitions
BST *CreateBST(void)
{
	BST *ret = NULL;
	ret = (BST *)malloc(sizeof(BST));
	ret->root = NULL;
	ret->size = 0;

	return ret;
}

BST *Search(BST *bstArg, char *searchArg, BST_NODE **outputStore)
{
	BST_NODE *current = NULL;

	if (bstArg==NULL){
		PRINTF("ERROR: bstArg is NULL.\n");
		return NULL;
	}
	
	if (bstArg->root == NULL)
		return NULL;

	current = bstArg->root;

	while(1){
		if (strcmp(current->name, searchArg) == 0){
			*outputStore = current;
			return bstArg;
		}

		if (strcmp(current->name, searchArg) < 0){
			if (current->right != NULL){
				current = current->right;
				continue;
			}
			//else if (current->right == NULL)
			return NULL;
		}

		if (strcmp(current->name, searchArg) > 0){
			if (current->left != NULL){
				current = current->left;
				continue;
			}
			//else if (current->left == NULL)
			return NULL;
		}
	}
}

BST *Add(BST *bstArg, char *addName, char *addDsc)
{
	BST_NODE *current = NULL;

	if (bstArg==NULL){
		PRINTF("ERROR: bstArg is NULL.\n");
		return NULL;
	}

	if (bstArg->root == NULL){
		if (bstArg->size != 0){
			PRINTF("ERROR: bstArg is broken somewhere.\n");
			return NULL;
		}
		bstArg->root = (BST_NODE *)malloc(sizeof(BST_NODE));
		bstArg->root->left = NULL;
		bstArg->root->right = NULL;
		strncpy(bstArg->root->name, addName, STRING_LEN);
		strncpy(bstArg->root->description, addDsc, STRING_LEN);
		bstArg->size += 1;
		return bstArg;
	}
	
	current = bstArg->root;

	while(1){
		if (strcmp(current->name, addName) == 0)
			return NULL;

		if (strcmp(current->name, addName) < 0){
			if (current->right != NULL){
				current = current->right;
				continue;
			}
			//else if (current->right == NULL)
			current->right = (BST_NODE *)malloc(sizeof(BST_NODE));
			strncpy(current->right->name, addName, STRING_LEN);
			strncpy(current->right->description, addDsc, STRING_LEN);
			current->right->left = NULL;
			current->right->right = NULL;
			bstArg->size += 1;
			return bstArg;
		}
		
		if (strcmp(current->name, addName) > 0){
			if (current->left != NULL){
				current = current->left;
				continue;
			}
			//else if (current->left == NULL)
			current->left = (BST_NODE *)malloc(sizeof(BST_NODE));
			strncpy(current->left->name, addName, STRING_LEN);
			strncpy(current->left->description, addDsc, STRING_LEN);
			current->left->left = NULL;
			current->left->right = NULL;
			bstArg->size += 1;
			return bstArg;
		}
	}
}

BST *Delete(BST *bstArg, char *deleteArg)
{
	BST_NODE *current = NULL;
	BST_NODE *parent = NULL;
	DIRECTION direction = NONE;
	BST_NODE *temp = NULL;
	BST_NODE *successor = NULL;
	BST_NODE *parent_of_successor = NULL;

	if (bstArg==NULL){
		PRINTF("ERROR: bstArg is NULL.\n");
		return NULL;
	}

	if (deleteArg == NULL){
		PRINTF("ERROR: deleteArg is NULL.\n");
		return NULL;
	}

	if (bstArg->root == NULL)
		return NULL;
	
	current = bstArg->root;
	while(1){
		if (current==NULL)
			return NULL;
		
		if (strcmp(current->name, deleteArg)==0)
			break;

		if (strcmp(current->name, deleteArg)>0){
			parent = current;
			current = current->left;
			direction = LEFT;
			continue;
		}

		if (strcmp(current->name, deleteArg)<0){
			parent = current;
			current = current->right;
			direction = RIGHT;
			continue;
		}
	}

	//Exception Handling.
	if (strcmp(current->name, deleteArg) != 0){
		PRINTF("ERROR: Something unexpected happened.\n");
		return NULL;
	}

	//When the current doesn't have any child.
	if (current->left == NULL && current->right == NULL){
		if (current == bstArg->root){
			free(bstArg->root);
			bstArg->root = NULL;
			bstArg->size -= 1;
			return bstArg;
		}

		switch (direction){
		case LEFT:
			parent->left = NULL;
			break;
		case RIGHT:
			parent->right = NULL;
			break;
		}
		free(current);
		bstArg->size -= 1;
		return bstArg;
	}

	//When the current node has only a right child.
	if (current->left == NULL && current->right != NULL){
		if (current == bstArg->root){
			bstArg->root = current->right;
			free(current);
			bstArg->size -= 1;
			return bstArg;
		}

		switch (direction){
		case LEFT:
			parent->left = current->right;
			break;
		case RIGHT:
			parent->right = current->right;
			break;
		}
		bstArg->size -= 1;
		free(current);
		return bstArg;
	}

	//When the current node has only a left child.
	if (current->left != NULL && current->right == NULL)
	{
		if (current == bstArg->root){
			bstArg->root = current->left;
			free(current);
			bstArg->size -= 1;
			return bstArg;
		}

		switch (direction){
		case LEFT:
			parent->left = current->left;
			break;
		case RIGHT:
			parent->right = current->left;
			break;
		}
		bstArg->size -= 1;
		free(current);
		return bstArg;
	}

	//When the current node has both left and right children.
	if (current->left == NULL || current->right == NULL){
		PRINTF("ERROR: Something unexpected occured.\n");
		return NULL;
	}

	parent_of_successor = current;
	successor = current->right;
	if (successor->left == NULL){
		strncpy(current->name, successor->name, STRING_LEN);
		strncpy(current->description, successor->description, STRING_LEN);
		current->right = successor->right;
		free(successor);
		bstArg->size -= 1;
		return bstArg;
	}

	while(1){
		parent_of_successor = successor;
		successor = successor->left;

		if (successor->left != NULL)
			continue;

		break;
	}

	strncpy(current->name, successor->name, STRING_LEN);
	strncpy(current->description, successor->description, STRING_LEN);
	parent_of_successor->left = successor->right;
	bstArg->size -= 1;
	free(successor);

	return bstArg;
}

int CleanBST(BST *bstArg)
{
	BST_NODE *popOutput = NULL;
	DEQUE *traverseResult = NULL;
	
	if (bstArg==NULL){
		PRINTF("ERROR: bstArg is NULL.\n");
		return -1;
	}

	if (bstArg->root = NULL){
		free(bstArg);
		return 0;
	}

	traverseResult = InorderTraverse(bstArg);

	while(PopLeft(traverseResult, &popOutput) != NULL)
		free(popOutput);

	if (CleanDeque(traverseResult) != 0){
		PRINTF("ERROR: CleanDeque( ) failed.\n");
		return -1;
	}

	bstArg->root = NULL;
	bstArg->size = 0;

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

DEQUE *PushRight(DEQUE *dequeArg, BST_NODE *inputArg)
{
	//Exception Handling1
	if (dequeArg == NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (inputArg == NULL){
		PRINTF("ERROR: inputArg is NULL.\n");
		return NULL;
	}

	//When the deque is empty currently.
	if (dequeArg->begin == NULL && dequeArg->end == NULL){
		dequeArg->begin = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));
		dequeArg->begin->data = inputArg;
		dequeArg->begin->next = NULL;
		dequeArg->end = dequeArg->begin;
		return dequeArg;
	}

	//Exception Handling3
	if (dequeArg->end->next != NULL){
		PRINTF("ERROR: dequeArg->end->next is not NULL.\n");
		return NULL;
	}

	dequeArg->end->next = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));
	dequeArg->end->next->data = inputArg;
	dequeArg->end->next->prev = dequeArg->end;
	dequeArg->end->next->next = NULL;
	dequeArg->end = dequeArg->end->next;
	
	return dequeArg;
}

DEQUE *PopRight(DEQUE *dequeArg, BST_NODE **outputStore) //Stack Popping
{
	//Exception Handling1
	if (dequeArg == NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (outputStore == NULL){
		PRINTF("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the deque is empty currently.
	if (dequeArg->begin == NULL && dequeArg->end == NULL)
		return NULL;

	//When the deque has only an element currently.
	if (dequeArg->begin == dequeArg->end){
		*outputStore = dequeArg->begin->data;
		free(dequeArg->begin);
		dequeArg->begin = NULL;
		dequeArg->end = NULL;
		return dequeArg;
	}

	*outputStore = dequeArg->end->data;
	dequeArg->end = dequeArg->end->prev;
	free(dequeArg->end->next);
	dequeArg->end->next = NULL;
	return dequeArg;
}

DEQUE *PopLeft(DEQUE *dequeArg, BST_NODE **outputStore) //Queue Dequeuing
{
	//Exception Handling1
	if (dequeArg == NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (outputStore == NULL){
		PRINTF("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the deque is empty currently.
	if (dequeArg->begin == NULL && dequeArg->end == NULL)
		return NULL;

	//When the deque has only an element currently.
	if (dequeArg->begin == dequeArg->end){
		*outputStore = dequeArg->begin->data;
		free(dequeArg->begin);
		dequeArg->begin = NULL;
		dequeArg->end = NULL;
		return dequeArg;
	}

	*outputStore = dequeArg->begin->data;
	dequeArg->begin = dequeArg->begin->next;
	free(dequeArg->begin->prev);
	dequeArg->begin->prev = NULL;
	return dequeArg;
}

int CleanDeque(DEQUE *dequeArg)
{
	BST_NODE *temp = NULL;

	if (dequeArg == NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return -1;
	}

	if (dequeArg->begin == NULL){
		free(dequeArg);
		return 0;
	}

	while(PopRight(dequeArg, &temp) != NULL)
		;
	free(dequeArg);

	return 0;
}

DEQUE *InorderTraverse(BST *bstArg)
{
	DEQUE *DFS_Deque = CreateDeque();
	DEQUE *output_Deque = CreateDeque();
	BST_NODE *current = NULL;
	int loopCtl1=1, loopCtl2=1;

	if (bstArg == NULL){
		PRINTF("ERROR: bstArg is NULL.\n");
		return NULL;
	}

	if (bstArg->root == NULL)
		return output_Deque;

	current = bstArg->root;

	while(loopCtl1){
		PushRight(DFS_Deque, current);
		current = current->left;
		if (current != NULL)
			continue;

		//when the current becomes NULL after moving to left child. 
		while(loopCtl2){
			if (PopRight(DFS_Deque, &current)==NULL){
				loopCtl1 = 0;
				break; //When the deque is empty. Traversal is completed.
			}

			//visit check.
			PushRight(output_Deque, current);
			
			current = current->right;
			if (current != NULL)
				break;

			//when the current becomes NULL after moving to right child.
			continue;
		}
	}

	if (CleanDeque(DFS_Deque)){
		PRINTF("ERROR: CleanDeque(DFS_Deque) Failed.\n");
		return NULL;
	}

	return output_Deque;
}
