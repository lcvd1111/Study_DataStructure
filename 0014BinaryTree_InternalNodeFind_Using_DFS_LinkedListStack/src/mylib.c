#include "mylib.h"

//Function Definitions
BINTREE_NODE *MakeChild(BINTREE_NODE *parent, CHILD_SELECTOR selector, int lArg, int rArg)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch (selector){
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
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
		parent->right->right = NULL;
		parent->right->header = NULL;
		break;
	case BOTH:
		if (parent->left!=NULL || parent->right!=NULL){
			PRINTF("ERROR: parent already has a child.\n");
			return NULL;
		}
		
		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->data = lArg;
		parent->left->left = NULL;
		parent->left->right = NULL;
		parent->left->header = NULL;
		
		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
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

STACK *CreateStack(void)
{
	STACK *ret = NULL;
	ret = (STACK *)malloc(sizeof(STACK));

	//Initial state is set to 'Empty' by default.
	ret->begin = NULL;
	ret->end = NULL;
	return ret;
}

STACK *Push(STACK *stackArg, BINTREE_NODE *binArg, ACTION triedAction)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	//when the stack is empty.
	if (stackArg->begin == NULL && stackArg->end == NULL){
		stackArg->begin = (STACK_NODE *)malloc(sizeof(STACK_NODE));
		stackArg->end = stackArg->begin;
		stackArg->begin->addressData = binArg;
		stackArg->begin->lastAction = triedAction;
		stackArg->begin->next = NULL;
		stackArg->begin->prev = NULL;
		return stackArg;
	}

	if(stackArg->end->next != NULL){
		PRINTF("ERROR: end->next is not NULL.\n");
		return NULL;
	}

	stackArg->end->next = (STACK_NODE *)malloc(sizeof(STACK_NODE));
	stackArg->end->next->addressData = binArg;
	stackArg->end->next->lastAction = triedAction;
	stackArg->end->next->prev = stackArg->end;
	stackArg->end->next->next = NULL;
	stackArg->end = stackArg->end->next;	

	return stackArg;
}

STACK *Pop(STACK *stackArg, STACK_NODE *outputStore)
{
	if (stackArg == NULL){
		PRINTF("ERROR: stackArg is NULL.\n");
		return NULL;
	}

	//when the stack is empty.
	if (stackArg->begin == NULL && stackArg->end == NULL){
		return NULL;
	}

	outputStore->addressData = stackArg->end->addressData;
	outputStore->lastAction = stackArg->end->lastAction;
	outputStore->prev = NULL;
	outputStore->next = NULL;

	///When the stack has only an element.
	if (stackArg->begin == stackArg->end){
		free(stackArg->end);
		stackArg->begin = NULL;
		stackArg->end = NULL;
		return stackArg;
	}

	stackArg->end=stackArg->end->prev;
	free(stackArg->end->next);
	stackArg->end->next = NULL;

	return stackArg;
}

STACK *EmptyStack(STACK *stackArg)
{
	STACK_NODE dummy;

	//When the stack is already empty.
	if (stackArg->begin == NULL && stackArg->end == NULL){
		return stackArg;
	}

	while(Pop(stackArg, &dummy) != NULL)
		;

	return stackArg;
}

int DeleteStack(STACK *stackArg)
{
	if(EmptyStack(stackArg) != stackArg){
		PRINTF("ERROR: EmptyStack( ) failed.\n");
		return -1;
	}

	free(stackArg);

	return 0;
}

int CheckExternal(BINTREE_NODE *parent)
{
	if (parent->header == NULL){
		PRINTF("ERROR: parent->header is NULL.\n");
		return -1;
	}

	if (parent->left == NULL && parent->right == NULL)
		return 1;
	else
		return 0;
}

int FindSubInternalNodes(BINTREE_NODE *parent, CHILD_SELECTOR selector)
{	
	if (parent->header == NULL){
		PRINTF("ERROR: parent's header is NULL.\n");
		return -1;
	}

	switch (selector){
	case LEFT:
		if ( ((HEADER_DATA *)(parent->left->header))->externalFlag ){
			((HEADER_DATA *)(parent->header))->left_Sub_Internal = 0;
			break;
		}

		((HEADER_DATA *)(parent->header))->left_Sub_Internal = 
			((HEADER_DATA*)(parent->left->header))->left_Sub_Internal +
			((HEADER_DATA*)(parent->left->header))->right_Sub_Internal + 1;
		break;
	case RIGHT:
		if ( ((HEADER_DATA *)(parent->right->header))->externalFlag ){
			((HEADER_DATA *)(parent->header))->right_Sub_Internal = 0;
			break;
		}
		
		((HEADER_DATA *)(parent->header))->right_Sub_Internal = 
			((HEADER_DATA*)(parent->right->header))->left_Sub_Internal +
			((HEADER_DATA*)(parent->right->header))->right_Sub_Internal + 1;
		break;
	default:
		PRINTF("ERROR: Wrong selector value.\n");
		return -1;
		break;
	}

	return 0;
}

int FindInternalNodes(BINTREE_NODE *root)
{
	STACK *DFS_Stack = NULL;
	STACK_NODE outputStore;
	BINTREE_NODE *current = NULL;
	int ret = 0;
	int i=1, j=1, k=1;

	if (root==NULL){
		return 0;
	}

	if (root->left == NULL || root->right == NULL){
		return 0;
	}

	DFS_Stack = CreateStack();

	current = root;

	while(i){
		if (current->header == NULL){
			current->header = (HEADER_DATA *)malloc(sizeof(HEADER_DATA));
			if (current->header == NULL){
				PRINTF("ERROR: malloc( ) failed.\n");
				return -1;
			}
		}

		((HEADER_DATA *)(current->header))->externalFlag = CheckExternal(current);
		
		if (!(((HEADER_DATA *)(current->header))->externalFlag)){
			Push(DFS_Stack, current, TRIED_LEFT);
			current = current->left;
			
			if (current !=NULL)
				continue;

			Pop(DFS_Stack, &outputStore);
			current = outputStore.addressData;
			((HEADER_DATA *)(current->header))->left_Sub_Internal = 0;
			
			while (j){
				Push(DFS_Stack, current, TRIED_RIGHT);
				current = current->right;

				if (current != NULL)
					break;
				
				Pop(DFS_Stack, &outputStore);
				current = outputStore.addressData;
				((HEADER_DATA *)(current->header))->right_Sub_Internal = 0;

				while (k){
					if(Pop(DFS_Stack, &outputStore)==NULL){
						i = 0;
						j = 0;
						break;
					}
					
					current = outputStore.addressData;

					if (outputStore.lastAction == TRIED_LEFT){
						if (FindSubInternalNodes(current, LEFT)){
							PRINTF("ERROR: FindSubInternalNodes( , LEFT) failed.\n");
							return -1;
						}
						break;
					}

					if (FindSubInternalNodes(current, RIGHT)){
						PRINTF("ERROR: FindSubInternalNodes( , RIGHT) failed.\n");
						return -1;
					}
					continue;
				}
			}
		}
		else{
			while (k){
				if(Pop(DFS_Stack, &outputStore)==NULL){
					i = 0;
					j = 0;
					break;
				}
				
				current = outputStore.addressData;

				if (outputStore.lastAction == TRIED_LEFT){
					if (FindSubInternalNodes(current, LEFT)){
						PRINTF("ERROR: FindSubInternalNodes( , LEFT) failed.\n");
						return -1;
					}
					
					Push(DFS_Stack, current, TRIED_RIGHT);
					current = current->right;

					if (current != NULL)
						break;

					Pop(DFS_Stack, &outputStore);
					current = outputStore.addressData;
					((HEADER_DATA *)(current->header))->right_Sub_Internal = 0;

					continue;
				}

				if (FindSubInternalNodes(current, RIGHT)){
					PRINTF("ERROR: FindSubInternalNodes( , RIGHT) failed.\n");
					return -1;
				}
				continue;
			}
		}
	}

	ret = ((HEADER_DATA *)(root->header))->left_Sub_Internal +
							((HEADER_DATA *)(root->header))->right_Sub_Internal + 1;
	
	DeleteStack(DFS_Stack);

	return ret;
}

int DeleteBintree(BINTREE_NODE *root)
{
	int ret = 0;
	BINTREE_NODE *current = NULL;
	STACK *DFSStack = NULL;
	STACK *resultStack = NULL;
	STACK_NODE popOutput;
	int i=1, j=1;

	current = root;

	if (current==NULL){
		return 0;
	}

	DFSStack = CreateStack();
	resultStack = CreateStack();

	while(i){
		Push(resultStack, current, TRIED_NONE);
		Push(DFSStack, current, TRIED_LEFT);
		current = current->left;

		if (current != NULL)
			continue;

		Pop(DFSStack, &popOutput);

		current = popOutput.addressData;

		while(1){
			current = current->right;

			if (current != NULL)
				break;

			if(Pop(DFSStack, &popOutput)==NULL){
				i = 0;
				break;
			}

			current = popOutput.addressData;
		}
	}

	DeleteStack(DFSStack);

	while(Pop(resultStack, &popOutput) != NULL){
		current = popOutput.addressData;

		if (current->header != NULL)
			free(current->header);

		free(current);
	}
	
	DeleteStack(resultStack);

	return ret;
}
