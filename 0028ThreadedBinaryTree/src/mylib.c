#include "mylib.h"

//Function Definitions
BINTREE_NODE *Insert(BINTREE_NODE *root, int arg)
{
	BINTREE_NODE *current = NULL;

	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	current = root;

	while(1){
		if (arg > current->data){
			if (current->right == NULL){
				current->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
				current->right->data = arg;
				current->right->left = NULL;
				current->right->right = NULL;
				return root;
			}
			current = current->right;
			continue;
		}
		else if (arg < current->data){
			if (current->left == NULL){
				current->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
				current->left->data = arg;
				current->left->left = NULL;
				current->left->right = NULL;
				return root;
			}
			current = current->left;
			continue;
		}
		else if (arg == current->data){
			PRINTF("ERROR: Value already exists in the tree.\n");
			return NULL;
		}

		PRINTF("ERROR: Unexpected situations happened.\n");
		return NULL;
	}
}

DEQUE *CreateDeque(void)
{
	DEQUE *ret = (DEQUE *)malloc(sizeof(DEQUE));

	ret->begin = NULL;
	ret->end = NULL;

	return ret;
}

DEQUE *PushLeft(DEQUE *dequeArg, BINTREE_NODE *binArg)
{
	if (dequeArg == NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return NULL;
	}

	if (binArg==NULL){
		PRINTF("ERROR: binArg is NULL.\n");
		return NULL;
	}

	//When the Deque is empty.
	if (dequeArg->begin == NULL && dequeArg->end == NULL) {
		dequeArg->begin = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));
		dequeArg->end = dequeArg->begin;
		dequeArg->begin->addressData = binArg;
		dequeArg->begin->prev = NULL;
		dequeArg->begin->next = NULL;
		return dequeArg;
	}

	if (dequeArg->begin->prev != NULL){
		PRINTF("ERROR: dequeArg->begin->prev != NULL.\n");
		return NULL;
	}

	dequeArg->begin->prev = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));
	dequeArg->begin->prev->next = dequeArg->begin;
	dequeArg->begin->prev->prev = NULL;
	dequeArg->begin->prev->addressData = binArg;
	dequeArg->begin = dequeArg->begin->prev;
	
	return dequeArg;
}

BINTREE_NODE *PopLeft(DEQUE *dequeArg)
{
	BINTREE_NODE *ret = NULL;

	if (dequeArg == NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return NULL;
	}

	//When the Deque is empty.
	if (dequeArg->begin == NULL && dequeArg->end == NULL){
		return NULL;
	}

	//When the Deque only has an element.
	if (dequeArg->begin == dequeArg->end){
		ret = dequeArg->begin->addressData;
		free(dequeArg->begin);
		dequeArg->begin = NULL;
		dequeArg->end = NULL;
		return ret;
	}

	ret = dequeArg->begin->addressData;
	dequeArg->begin = dequeArg->begin->next;
	free(dequeArg->begin->prev);
	dequeArg->begin->prev = NULL;

	return ret;
}

DEQUE *PushRight(DEQUE *dequeArg, BINTREE_NODE *binArg)
{
	if (dequeArg==NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return NULL;
	}

	if (binArg==NULL){
		PRINTF("ERROR: binArg is NULL.\n");
		return NULL;
	}

	//When the deque is empty.
	if (dequeArg->begin == NULL && dequeArg->end == NULL){
		dequeArg->begin = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));
		dequeArg->begin->addressData = binArg;
		dequeArg->end = dequeArg->begin;
		dequeArg->begin->prev = NULL;
		dequeArg->begin->next = NULL;
		return dequeArg;
	}

	if (dequeArg->end->next != NULL){
		PRINTF("ERROR: deqeuArg->end->next != NULL");
		return NULL;
	}

	dequeArg->end->next = (DEQUE_NODE *)malloc(sizeof(DEQUE_NODE));
	dequeArg->end->next->prev = dequeArg->end;
	dequeArg->end->next->next = NULL;
	dequeArg->end->next->addressData = binArg;
	dequeArg->end = dequeArg->end->next;
	return dequeArg;
}

BINTREE_NODE *PopRight(DEQUE *dequeArg)
{
	BINTREE_NODE *ret = NULL;
	
	if (dequeArg == NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return NULL;
	}

	//When the deque is empty.
	if (dequeArg->begin == NULL && dequeArg->end == NULL)
		return NULL;

	//When the deque has only an element.
	if (dequeArg->begin == dequeArg->end){
		ret = dequeArg->begin->addressData;
		free(dequeArg->begin);
		dequeArg->begin = NULL;
		dequeArg->end = NULL;
		return ret;
	}

	ret = dequeArg->end->addressData;
	dequeArg->end = dequeArg->end->prev;
	free(dequeArg->end->next);
	dequeArg->end->next = NULL;

	return ret;
}

DEQUE *EmptyDeque(DEQUE *dequeArg)
{
	if (dequeArg == NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return NULL;
	}

	if (dequeArg->begin == NULL && dequeArg->end == NULL){
		return dequeArg;
	}

	while(PopRight(dequeArg) != NULL)
		;

	if (dequeArg->begin != NULL || dequeArg->end != NULL){
		PRINTF("ERROR: Unexpected situation happened.\n");
		return NULL;
	}

	return dequeArg;
}

int DeleteDeque(DEQUE *dequeArg)
{
	if (dequeArg == NULL){
		PRINTF("ERROR: dequeArg is NULL.\n");
		return -1;
	}

	if (dequeArg->begin == NULL && dequeArg->end == NULL){
		free(dequeArg);
		return 0;
	}

	if (EmptyDeque(dequeArg) == NULL){
		PRINTF("EROR: EmptyDeque( ) failed.\n");
		return -1;
	}

	if (dequeArg->begin != NULL || dequeArg->end != NULL){
		PRINTF("ERROR: Unexpected situation happened.\n");
		return -2;
	}

	free(dequeArg);

	return 0;
}

BINTREE_NODE *InorderTraverse(BINTREE_NODE *root, DEQUE *output)
{
	BINTREE_NODE *current = NULL;
	DEQUE *DFS_Deque = NULL;
	int i=1, j=1, k=1;

	DFS_Deque = CreateDeque();

	if (root==NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	if (output == NULL){
		PRINTF("ERROR: output storage Deque is NULL.\n");
		return NULL;
	}

	current = root;

	while (i){
		PushRight(DFS_Deque, current);
		current = current->left;

		if (current != NULL)
			continue;

		//When the current becomes null after moving to left child.
		current = PopRight(DFS_Deque);
		while(j){
			//printf("Visited: %d\n", current->data);
			PushRight(output, current);

			current = current->right;
			if (current != NULL)
				break;
		
			//When the current becomes null after moving to right child.
			current = PopRight(DFS_Deque);
			
			if (current == NULL){
				i=0;
				break;
			}
		}
	}

	if (DFS_Deque->begin != NULL || DFS_Deque->end != NULL){
		PRINTF("ERROR: DFS_Deque is NOT empty.\n");
		return NULL;
	}

	//printf("Traversal Complete.\n");
	DeleteDeque(DFS_Deque);
	return root;
}

BINTREE_NODE *LevelorderTraverse(BINTREE_NODE *root, DEQUE *output)
{
	BINTREE_NODE *current = NULL;
	DEQUE *BFS_Deque = NULL;

	if (root==NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	if (output==NULL){
		PRINTF("ERROR: output Storage Deque is NULL.\n");
		return NULL;
	}

	BFS_Deque = CreateDeque();
	current = root;

	while(1){
		//printf("Visited: %d\n", current->data);
		PushRight(output, current);

		if (current->left != NULL)
			PushLeft(BFS_Deque, current->left);

		if (current->right != NULL)
			PushLeft(BFS_Deque, current->right);

		current = PopRight(BFS_Deque);
		if (current == NULL)
			break;
	}

	//printf("Traversal Complete.\n");
	DeleteDeque(BFS_Deque);
	return root;
}

BINTREE_NODE *CopyBintree(BINTREE_NODE *src)
{
	BINTREE_NODE *dst_root = NULL;
	BINTREE_NODE *src_current = NULL;
	BINTREE_NODE *dst_current = NULL;
	DEQUE *BFS_Deque_src = NULL;
	DEQUE *BFS_Deque_dst = NULL;

	if(src == NULL){
		PRINTF("ERROR: src is NULL.\n");
		return NULL;
	}

	src_current = src;
	BFS_Deque_src = CreateDeque();
	BFS_Deque_dst = CreateDeque();

	while(1){
		dst_current = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		dst_current->data = src_current->data;
		dst_current->left = NULL;
		dst_current->right = NULL;
		if (src_current->left != NULL){
			dst_current->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			dst_current->left->data = src_current->left->data;
			PushRight(BFS_Deque_src, src_current->left);
			PushRight(BFS_Deque_dst, dst_current->left);
		}

		if (src_current->right != NULL){
			dst_current->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
			dst_current->right->data = src_current->right->data;
			PushRight(BFS_Deque_src, src_current->right);
			PushRight(BFS_Deque_dst, dst_current->right);
		}

		src_current = PopLeft(BFS_Deque_src);
		if (src_current == NULL)
			break;

		dst_current = PopLeft(BFS_Deque_dst);
	}

	DeleteDeque(BFS_Deque_src);
	DeleteDeque(BFS_Deque_dst);

	return dst_root;
}

BINTREE_NODE *MakeThreadedTree(BINTREE_NODE *src);

BINTREE_NODE *ThreadedTraverse(BINTREE_NODE *root, DEQUE *output);

int *DeleteBintree(BINTREE_NODE *root)
{
	DEQUE *BFS_Deque = NULL;
	BINTREE_NODE *current = NULL;

	if (root == NULL){
		PRINTF("ERROR: root is NULL.\n");
		return NULL;
	}

	if (root->left==NULL && root->right==NULL){
		free(root);
		return 0;
	}

	BFS_Deque = CreateDeque();
	current = root;

	while(1){
		if (current->left != NULL)
			PushRight(BFS_Deque, current->left);

		if (current->right != NULL)
			PushRight(BFS_Deque, current->right);

		free(current);

		current = PopLeft(BFS_Deque);
		if (current == NULL)
			break;
	}

	DeleteDeque(BFS_Deque);
	return 0;
}
