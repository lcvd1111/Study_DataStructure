#include "mylib.h"

//Function Definitions
////SPLAY BST Operations
SPLAY_BST *Create_SplayBST(void);
SPLAY_BST *Insert_SplayBST(SPLAY_BST *BST, int value);
SPLAY_BST_NODE *Search_SplayBST(SPLAY_BST *BST, int value);
SPLAY_BST *Delete_SplayBST(SPLAY_BST *BST, int value);


int Remove_SplayBST(SPLAY_BST *BST)
{
	DEQUE *BFS_Deque = NULL;
	SPLAY_BST_NODE *popOutput = NULL;

	//Exception Handling
	if (BST == NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return -1;
	}

	//When the BST is empty. 
	if (BST->root == NULL){
		free(BST);
		return 0;
	}
	
	BFS_Deque = CreateDeque();
	
	if (PushLeft(BFS_Deque,BST->root) != BFS_Deque){
		PRINTF("ERROR: PushLeft(BFS_Deque, BST->root) failed.\n");
		return -1;
	}

	//BFS Start.
	while(1){
		if (PopRight(BFS_Deque, &popOutput) != BFS_Deque)
			break; //When the BFS end.
		
		if (popOutput->left != NULL){
			if (PushLeft(BFS_Deque, popOutput->left) != BFS_Deque){
				PRINTF("ERROR: PushLeft(BFS_Deque, BST->left) failed.\n");
				return -1;
			}
		}

		if (popOutput->right != NULL){
			if (PushLeft(BFS_Deque, popOutput->right) != BFS_Deque){
				PRINTF("ERROR: PushLeft(BFS_Deque, BST->right) failed.\n");
				return -1;
			}
		}

		free(popOutput);
	}

	if (RemoveDeque(BFS_Deque)){
		PRINTF("ERROR: RemoveDeque( ) failed.\n");
		return -1;
	}

	return 0;
}

////Building Blocks for SPLAY BST Operations
SPLAY_BST_NODE *Insert_BST(SPLAY_BST *BST, int value)
{
	SPLAY_BST_NODE *current = NULL;

	//Exception Handling
	if (BST == NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	//When the BST is empty.
	if (BST->root == NULL){
		BST->root = (SPLAY_BST_NODE *)malloc(sizeof(SPLAY_BST_NODE));
		BST->root->data = value;
		BST->root->parent = NULL;
		BST->root->left = NULL;
		BST->root->right = NULL;
		return NULL;
	}

	current = BST->root;
	//When the value already exists in BST.
	while(1){
		if (current->data == value)
			return NULL;

		//When the value is smaller than current node.
		if (current->data > value){
			if (current->left != NULL){
				current = current->left;
				continue;
			}
			//When the current node doens't have left child.
			current->left = (SPLAY_BST_NODE *)malloc(sizeof(SPLAY_BST_NODE));
			current->left->data = value;
			current->left->parent = current;
			current->left->left = NULL;
			current->left->right = NULL;
			return (current->left);
		}

		//When the value is bigger than current node.
		if (current->data > value){
			if (current->right != NULL){
				current = current->right;
				continue;
			}
			//When the current node doesn't have right child.
			current->right = (SPLAY_BST_NODE *)malloc(sizeof(SPLAY_BST_NODE));
			current->right->data = value;
			current->right->parent = current;
			current->right->left = NULL;
			current->right->right = NULL;
			return (current->right);
		}

		//Exception Handling
		PRINTF("ERROR: Unexpected event occurs\n");
		return NULL;
	}
}

SPLAY_BST_NODE *Search_BST(SPLAY_BST *BST, int value)
{
	SPLAY_BST_NODE *current = NULL;

	//Excption Handling
	if (BST == NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	if (BST->root == NULL){
		PRINTF("ERROR: BST->root is NULL.\n");
		return NULL;
	}

	current = BST->root;

	while(1){
		//When the searching fail
		if (current==NULL){
			return NULL;
		}

		//When the searching sucess
		if (current->data == value){
			return current;
		}

		//When the value is smaller than current node
		if (current->data > value){
			current = current->left;
			continue;
		}

		//When the value is bigger than current node
		if (current->data < value){
			current = current->right;
			continue;
		}

		//Exception Handing
		PRINTF("ERROR: Unexpected event occured.\n");
		return NULL;
	}
}

SPLAY_BST *Delete_BST(SPLAY_BST *BST, int value)
{
	SPLAY_BST_NODE *searchResult = NULL;

	//Exception Handling
	if (BST == NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	searchResult = SearchBST(BST, value);

	//When the element doesn't exist in BST
	if (searchResult == NULL)
		return NULL;

	//When element doesn't have a right child.
	if (searchResult->right == NULL){
		//When the element is a root node.
		if (searchResult->parent == NULL){
			//Exception Handling
			if (searchRestul != BST->root){
				PRINTF("ERROR: Unexpected Event occured.\n");
				return NULL;
			}
			BST->root = searchResult->left;
			free(BST->root);
			return BST;
		}

	}

}

SPLAY_BST_NODE *RotateLeft(SPLAY_BST *BST, SPLAY_BST_NODE *node);
SPLAY_BST_NODE *RotateRight(SPLAY_BST *BST, SPLAY_BST_NODE *node);

////Circular Deque Operations
CIRCULAR_DEQUE *CreateDeque(void)
{
	CIRCULAR_DEQUE *ret = (CIRCULAR_DEQUE *)malloc(sizeof(CIRCULAR_DEQUE));
	ret->begin = -1;
	ret->end = -1;
	return ret;
}

CIRCULAR_DEQUE *PushLeft(CIRCULAR_DEQUE *Deque, SPLAY_BST_NODE *inputArg)
{
	//Exception Handling
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return NULL;
	}

	if (inputArg==NULL){
		PRINTF("ERROR: inputArg is NULL.\n");
		return NULL;
	}

	//When the Deque is empty
	if (Deque->begin==-1 && Deque->end==-1){
		Deque->begin = 0;
		Deque->end = 0;
		(Deque->dequeArray)[Deque->begin] = inputArg;
		return Deque;
	}

	//When the Deque is full.
	if ((Deque->end + 1 == Deque->begin)||(Deque->end==DEQUE_MAX-1 && Deque->begin==0))
		return NULL;

	//Other remaining cases.
	Deque->begin -= 1;

	if (Deque->begin == -1)
		Deque->begin = DEQUE_MAX-1;

	(Deque->dequeArray)[Deque->begin] = inputArg;
	return Deque;
}

CIRCULAR_DEQUE *PopLeft(CIRCULAR_DEQUE *Deque, SPLAY_BST_NODE **outputStore)
{
	//Exception Handling
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return NULL;
	}

	if (outputStore==NULL){
		PRINTF("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the Deque is empty.
	if (Deque->begin==-1 && Deque->end==-1)
		return NULL;

	//When the Deque has only one element.
	if (Deque->begin == Deque->end){
		*outputStore = (Deque->dequeArray)[Deque->begin];
		Deque->begin = -1;
		Deque->end = -1;
		return Deque;
	}

	//Other remaining cases.
	*outputStore = (Deque->dequeArray)[Deque->begin];
	
	Deque->begin += 1;
	
	if (Deque->begin==DEQUE_MAX)
		Deque->begin = 0;

	return Deque;
}

CIRCULAR_DEQUE *PushRight(CIRCULAR_DEQUE *Deque, SPLAY_BST_NODE *inputArg)
{
	//Exception Handling
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return NULL;
	}

	if (inputArg==NULL){
		PRINTF("ERROR: inputArg is NULL.\n");
		return NULL;
	}
	
	//When the Deque is empty.
	if (Deque->begin==-1 && Deque->end==-1){
		Deque->begin=0;
		Deque->end=0;
		(Deque->dequeArray)[Deque->end] = inputArg;
		return Deque;
	}

	//When the Deque is full.
	if (Deque->end+1==Deque->begin || (Deque->end==DEQUE_MAX-1 && Deque->begin==0))
		return NULL;

	//Other remaining cases.
	Deque->end += 1;
	
	if (Deque->end == DEQUE_MAX)
		Deque->end = 0;

	(Deque->dequeArray)[Deque->end] = inputArg;
	return Deque;
}

CIRCULAR_DEQUE *PopRight(CIRCULAR_DEQUE *Deque, SPLAY_BST_NODE **outputStore)
{
	//Exception Handling
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return NULL;
	}

	if (outputStore==NULL){
		PRINTF("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//When the Deque is empty.
	if (Deque->begin==-1 && Deque->end==-1)
		return NULL;
	
	//When the Deque has only one element.
	if (Deque->begin == Deque->end){
		*outputStore = (Deque->dequeArray)[Deque->end];
		Deque->begin = -1;
		Deque->end = -1;
		return Deque;
	}

	//Other remaining cases.
	*outputStore = (Deque->dequeArray)[Deque->end];
	
	Deque->end -= 1;

	if (Deque->end==-1)
		Deque->end = DEQUE_MAX-1;

	return Deque;
}

int RemoveDeque(CIRCULAR_DEQUE *Deque)
{
	if (Deque==NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return -1;
	}

	free(Deque);

	return 0;
}
