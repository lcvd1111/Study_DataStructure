#include "mylib.h"

//Function Definitions
BINTREE_NODE *MakeChild
(BINTREE_NODE *parent, CHILD_SELECTOR selector, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch(selector){
	case LEFT:
		if(parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->left == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		parent->left->header = NULL;
		break;
	case RIGHT:
		if(parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->right == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		parent->right->header = NULL;
		break;
	case BOTH:
		if(!((parent->left==NULL)&&(parent->right==NULL))){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->left == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		parent->left->header = NULL;

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		if (parent->right == NULL){
			PRINTF("ERROR: malloc( ) failed.\n");
			return NULL;
		}
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right = NULL;
		parent->right->header = NULL;

		break;
	default:
		PRINTF("ERROR: Wrong selector Value.\n");
		return NULL;
		break;
	}
	return parent;
}

STACK *CreateStack(){
	STACK *ret = (STACK *)malloc(sizeof(STACK));
	if (ret==NULL){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	ret->stackArray = (WRAPPED_NODE *)malloc(STACK_MAX * sizeof(WRAPPED_NODE));
	if (ret->stackArray == NULL){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	ret->end = -1;

	return ret;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *binArg, ACTION action)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stack is NULL.\n");
		return NULL;
	}

	if(stackArg->end == STACK_MAX-1){
		PRINTF("ERROR: stack is full.\n");
		return NULL;
	}

	(stackArg->end)++;

	((stackArg->stackArray)[stackArg->end]).addressData = binArg;
	((stackArg->stackArray)[stackArg->end]).lastTried = action;

	return stackArg;
}

STACK *Pop(STACK *stackArg, WRAPPED_NODE *outputStorage)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stack is NULL.\n");
		return NULL;
	}

	if (stackArg->end == -1){
		//When stack is empty.
		return NULL;
	}
	outputStorage->addressData = ((stackArg->stackArray)[stackArg->end]).addressData;
	outputStorage->lastTried = ((stackArg->stackArray)[stackArg->end]).lastTried;
	
	(stackArg->end)--;

	return stackArg;
}

STACK *EmptyStack(STACK *stackArg)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stack is NULL.\n");
		return NULL;
	}

	if (stackArg->end == -1){
		//When stack is empty.
		return NULL;
	}

	stackArg->end = -1;

	return stackArg;
}

int DeleteStack(STACK *stackArg)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stack is NULL.\n");
		return -1;
	}

	if (stackArg->stackArray == NULL){
		PRINTF("ERROR: stack->stackArray is NULL.\n");
		return -2;
	}

	free(stackArg->stackArray);
	free(stackArg);

	return 0;
}

int FindHeight_DFS(BINTREE_NODE *root)
{
	STACK *myStack = NULL;
	BINTREE_NODE *current = root;
	WRAPPED_NODE output;
	int i=1, j=1, k=1;
	int ret = 0;
	if (current == NULL){
		//When the Bintree is empty.
		return 0;
	}

	myStack = CreateStack();
	
	while(i){
		if (current->header == NULL){
			current->header = (HEADER_DATA *)malloc(sizeof(HEADER_DATA));
		}
		Push(myStack, current, TRIED_LEFT);
		current = current->left;

		if (current != NULL){
			continue;
		}
		else if (current == NULL){
			Pop(myStack, &output);
			current = output.addressData;
			((HEADER_DATA *)(current->header))->left_Sub_Height = 0;
			while(j){
				Push(myStack, current, TRIED_RIGHT);
				current = current->right;

				if(current != NULL){
					break;
				}
				else if (current == NULL){
					Pop(myStack, &output);
					current = output.addressData;
					((HEADER_DATA *)(current->header))->right_Sub_Height = 0;
					while(k){
						if (Pop(myStack, &output) == NULL)
						{	
							j = 0;
							i = 0;
							break;
						}
						if (output.lastTried == TRIED_LEFT){
							current = output.addressData;
							FindSubHeight(current, LEFT);							
							break;
						}
						else if (output.lastTried == TRIED_RIGHT){
							current = output.addressData;
							FindSubHeight(current, RIGHT);
							continue;
						}
						else {
							PRINTF("ERROR occured.\n");
							return -1;
						}
					}
				}
			}
		}
	}

	ret = (((HEADER_DATA *)(root->header))->left_Sub_Height > ((HEADER_DATA *)(root->header))->right_Sub_Height) ?
			((HEADER_DATA *)(root->header))->left_Sub_Height : ((HEADER_DATA *)(root->header))->right_Sub_Height ;
	ret ++;

	DeleteStack(myStack);
	return ret;
}

int FindSubHeight(BINTREE_NODE *parent, CHILD_SELECTOR selector)
{
	if (parent->header == NULL){
		PRINTF("ERROR: parent->header == NULL.\n");
		return -1;
	}

	switch (selector){
	case LEFT:
		if (parent->left->header == NULL){
			PRINTF("ERROR: parent->left->header == NULL.\n");
			return -2;
		}
		((HEADER_DATA *)(parent->header))->left_Sub_Height = 
			(((HEADER_DATA *)(parent->left->header))->left_Sub_Height > ((HEADER_DATA *)(parent->left->header))->right_Sub_Height) ?
			((HEADER_DATA *)(parent->left->header))->left_Sub_Height : ((HEADER_DATA *)(parent->left->header))->right_Sub_Height; 
		(((HEADER_DATA *)(parent->header))->left_Sub_Height)++;
		break;
	case RIGHT:
		if (parent->right->header == NULL){
			PRINTF("EROOR: parent->right->header == NULL.\n");
			return -2;
		}
		((HEADER_DATA*)(parent->header))->right_Sub_Height =
			(((HEADER_DATA *)(parent->right->header))->left_Sub_Height > ((HEADER_DATA *)(parent->right->header))->right_Sub_Height) ?
			((HEADER_DATA *)(parent->right->header))->left_Sub_Height : ((HEADER_DATA *)(parent->right->header))->right_Sub_Height; 
		(((HEADER_DATA *)(parent->header))->right_Sub_Height)++;
		break;
	}

	return 0;
}

int DeleteBintree(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	WRAPPED_NODE output;
	STACK *traversingStack = NULL;
	STACK *resultStack = NULL;
	int i=1;

	current = root;
	traversingStack = CreateStack();
	resultStack = CreateStack();

	while(i){
		Push(resultStack, current, TRIED_NOTHING);
		Push(traversingStack, current, TRIED_LEFT);
		current = current->left;
		if (current != NULL)
			continue;
		else if (current == NULL){
			Pop(traversingStack, &output);
			current = output.addressData;
			while(1){
				current = current->right;
				if (current != NULL)
					break;
				else if (current == NULL){
					if(Pop(traversingStack, &output)==NULL){
						i = 0;
						break;
					}
					current = output.addressData;
				}
			}
		}
	}

	DeleteStack(traversingStack);
	while(Pop(resultStack, &output) != NULL){
		current = output.addressData;
		if (current->header != NULL)
			free(current->header);
		free(current);
	}

	DeleteStack(resultStack);
	return 0;
}
