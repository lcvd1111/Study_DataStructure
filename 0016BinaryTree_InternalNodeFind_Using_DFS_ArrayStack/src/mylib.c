#include "mylib.h"

//Function Definitions
STACK *CreateStack(void)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));
	
	if (ret==NULL){
		PRINTF("ERROR: malloc( ) failed.\n");
		return NULL;
	}

	for (int i = 0 ; i<STACK_MAX ; i++){
		(ret->stackArray)[i].addressData = NULL;
		(ret->stackArray)[i].triedAction = TRIED_NONE;
	}
	
	ret->end = 0;
	
	return ret;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *binArg, ACTION_SELECTOR action)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	if (binArg == NULL){
		PRINTF("ERROR: bintreeArg is NULL.\n");
		return NULL;
	}

	if (stackArg->end == STACK_MAX -1){
		//When the stack is full.
		PRINTF("ERROR: Stack is full.\n");
		return NULL;
	}

	(stackArg->end)++;

	if ((stackArg->stackArray)[stackArg->end].addressData != NULL){
		PRINTF("ERROR: New Position already has a data.\n");
		return NULL;
	}

	(stackArg->stackArray)[stackArg->end].addressData = binArg;
	(stackArg->stackArray)[stackArg->end].triedAction = action;

	return stackArg;
}

int Pop(STACK *stackArg, STACK_NODE *outputStorage)
{
	if (outputStorage == NULL){
		PRINTF("ERROR: outputStorage is NULL.\n");
		return -1;
	}

	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return -2;
	}

	if (stackArg->end == 0){
		//When the stack is empty.
		return 1;
	}

	outputStorage->addressData = (stackArg->stackArray)[stackArg->end].addressData;
	outputStorage->triedAction = (stackArg->stackArray)[stackArg->end].triedAction;

	if (outputStorage->addressData == NULL){
		PRINTF("ERROR: Popped Data is NULL.\n");
		return -3;
	}

	(stackArg->stackArray)[stackArg->end].addressData = NULL;
	(stackArg->stackArray)[stackArg->end].triedAction = TRIED_NONE;

	(stackArg->end)--;

	return 0;

}

int DeleteStack(STACK *stackArg)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return -1;
	}

	free(stackArg);
	return 0;
}

BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR select, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch (select){
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right= NULL;
		parent->left->header = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right= NULL;
		parent->right->header = NULL;
		break;
	case BOTH:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right= NULL;
		parent->left->header = NULL;

		if (parent->right != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->data = rArg;
		parent->right->left = NULL;
		parent->right->right= NULL;
		parent->right->header = NULL;
		break;
	default:
		PRINTF("ERROR: Wrong selector value.\n");
		return NULL;
	}
	
	return parent;
}

int CheckExternalNode(BINTREE_NODE *node)
{
	if (node==NULL){
		PRINTF("ERROR: node is NULL.\n");
		return -1;
	}

	if (node->header == NULL)
		node->header = (HEADER_DATA *)malloc(sizeof(HEADER_DATA));

	if (node->left == NULL && node->right == NULL){
		((HEADER_DATA *)(node->header))->externalFlag = 1;
		return 0;
	}

	((HEADER_DATA *)(node->header))->externalFlag = 0;
	return 0;
}

int UpdateInternalNode(BINTREE_NODE *node, CHILD_SELECTOR select)
{
	if (node==NULL){
		PRINTF("ERROR: node is NULL.\n");
		return -1;
	}

	if (node->header == NULL){
		PRINTF("ERROR: node->header is NULL.\n");
		return -2;
	}

	switch(select){
	case LEFT:
		if (node->left == NULL){
			PRINTF("ERROR: node->left is NULL.\n");
			return -3;
		}
		
		if (node->left->header == NULL){
			PRINTF("ERROR: node->left->header is NULL.\n");
			return -4;
		}

		if (((HEADER_DATA*)(node->left->header))->externalFlag){
			((HEADER_DATA *)(node->header))->leftSubTree_Internal = 0;
			break;
		}

		((HEADER_DATA *)(node->header))->leftSubTree_Internal = ((HEADER_DATA *)(node->left->header))->leftSubTree_Internal + ((HEADER_DATA *)(node->left->header))->rightSubTree_Internal + 1;
		break;
	case RIGHT:
		if (node->right == NULL){
			PRINTF("ERROR: node-right is NULL.\n");
			return -5;
		}
		
		if (node->right->header == NULL){
			PRINTF("ERROR: node->rightt->header is NULL.\n");
			return -6;
		}

		if (((HEADER_DATA *)(node->right->header))->externalFlag){
			((HEADER_DATA *)(node->header))->rightSubTree_Internal = 0;
			break;
		}

		((HEADER_DATA *)(node->header))->rightSubTree_Internal = ((HEADER_DATA *)(node->right->header))->leftSubTree_Internal + ((HEADER_DATA *)(node->right->header))->rightSubTree_Internal + 1;
		break;
	defualt:
		PRINTF("ERROR: wrong selector value.\n");
		return -1;
	}

	return 0;
}

int FindInternalNodes_DFS(BINTREE_NODE *root)
{
	STACK *DFS_Stack = NULL;
	STACK_NODE popOutput;
	BINTREE_NODE *current = root;
	int i=1, j=1, k=1;
	int ret = 0;

	if (root == NULL)
		return 0;

	if (root->left==NULL && root->right==NULL)
		return 0;

	DFS_Stack = CreateStack();
	
	while(i){
		if (CheckExternalNode(current)){
			PRINTF("ERROR: CheckExternalNode(current) failed.\n");
			return -1;
		}

		if (!(((HEADER_DATA *)(current->header))->externalFlag)){
			Push(DFS_Stack, current, TRIED_LEFT);
			current = current->left;

			if (current != NULL)
				continue;

			Pop(DFS_Stack, &popOutput);
			current = popOutput.addressData;
			((HEADER_DATA *)(current->header))->leftSubTree_Internal = 0;

			while(j){
				Push(DFS_Stack, current, TRIED_RIGHT);
				current = current->right;

				if (current != NULL)
					break;
			
				Pop(DFS_Stack, &popOutput);
				current = popOutput.addressData;
				((HEADER_DATA *)(current->header))->rightSubTree_Internal = 0;

				while(k){
POP_TIME:
					if(Pop(DFS_Stack, &popOutput)==1){
						if(root->header == NULL){
							PRINTF("ERROR: root->header is NULL.\n");
							return -1;
						}
						ret = ((HEADER_DATA *)(root->header))->leftSubTree_Internal + ((HEADER_DATA *)(root->header))->rightSubTree_Internal + 1;
						j=0;
						i=0;
						break;
					}

					current = popOutput.addressData;
					if (popOutput.triedAction==TRIED_LEFT){
						UpdateInternalNode(current, LEFT);
						break;
					}

					UpdateInternalNode(current, RIGHT);
				}
			}
		}
		else {
			goto POP_TIME;
		}
	}

	DeleteStack(DFS_Stack);

	return ret;
}

int DeleteBintree(BINTREE_NODE *root)
{
	BINTREE_NODE *current = NULL;
	STACK *DFS_Stack = NULL;
	STACK_NODE popOutput;
	STACK *result_Stack = NULL;
	int i = 1;

	DFS_Stack = CreateStack();
	result_Stack = CreateStack();
	
	current = root;

	while(i){
		Push(result_Stack, current, TRIED_NONE);
		Push(DFS_Stack, current, TRIED_LEFT);
		current = current->left;
		
		if (current != NULL)
			continue;

		Pop(DFS_Stack, &popOutput);
		current = popOutput.addressData;

		while(1){
			current = current->right;
			if (current != NULL)
				break;

			if (Pop(DFS_Stack, &popOutput)==1){
				i=0;
				break;
			}

			current = popOutput.addressData;
		}
	}

	while(Pop(result_Stack, &popOutput) != 1)
		free(popOutput.addressData);
	
	DeleteStack(DFS_Stack);
	DeleteStack(result_Stack);
	return 0;
}
