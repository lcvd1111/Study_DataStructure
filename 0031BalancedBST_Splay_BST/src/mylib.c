#include "mylib.h"

//Function Definitions
////SPLAY BST Operations
SPLAY_BST *Create_SplayBST(void)
{
	SPLAY_BST *ret = NULL;
	ret = (SPLAY_BST *)malloc(sizeof(SPLAY_BST));
	ret->root = NULL;
	return ret;
}

SPLAY_BST *Insert_SplayBST(SPLAY_BST *BST, int value)
{
	SPLAY_BST_NODE *current = NULL;

	//Exception Handling
	if (BST==NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	current = Insert_BST(BST, value);
	if(current==NULL){
		//When the element already exists in the BST.
		return NULL;
	}

	while(BST->root != current){
		if(current != Correction(BST, current)){
			PRINTF("ERROR: Correction( ) during the insertion failed.\n");
			return NULL;
		}
	}

	//Exception Handling
	if (BST->root != current){
		PRINTF("ERROR: Correction( ) wasn't done perfectly during the insertion.\n");
		return NULL;
	}

	return BST;
}

SPLAY_BST_NODE *Search_SplayBST(SPLAY_BST *BST, int value)
{
	SPLAY_BST_NODE *current = NULL;

	//Exception Handling
	if (BST==NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	current = Search_BST(BST, value);

	//When the element doesn't exist in the BST.
	if (current==NULL){
		return NULL;
	}

	while(BST->root != current){
		if (current != Correction(BST, current)){
			PRINTF("ERROR: Correction( ) during the searching failed.\n");
			return NULL;
		}
	}

	//Exception Handling
	if (BST->root != current){
		PRINTF("ERROR: Correction( ) wasn't done perfectly during the searching.\n");
		return NULL;
	}

	return current;
}

SPLAY_BST *Delete_SplayBST(SPLAY_BST *BST, int value)
{
	SPLAY_BST_NODE *current = NULL;

	//Exception Handling
	if (BST==NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	current = Search_BST(BST, value);


	//When the element doesn't exist in the BST.
	if (current==NULL){
		return NULL;
	}

	while(BST->root != current){
		if (current != Correction(BST, current)){
			PRINTF("ERROR: Correction( ) during the Deletion failed.\n");
			return NULL;
		}
	}

	//Exception Handling
	if (BST->root != current){
		PRINTF("ERROR: Correction( ) wasn't done perfectly during the Deletion.\n");
		return NULL;
	}

	if (BST != Delete_BST(BST, value)){
		PRINTF("ERROR: Delete_BST( ) during the Delte_SplayBST failed.\n");
		return NULL;
	}

	return BST;
}

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
		return BST->root;
	}

	current = BST->root;
	while(1){
		//When the value already exists in BST.
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
		if (current->data < value){
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
	SPLAY_BST_NODE *InorderPredecessor = NULL;
	
	//Exception Handling
	if (BST == NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	searchResult = Search_BST(BST, value);

	//When the element doesn't exist in BST
	if (searchResult == NULL)
		return NULL;

	//When element doesn't have a right child.
	if (searchResult->right == NULL){
		//When the element is a root node.
		if (searchResult->parent == NULL){
			//Exception Handling
			if (searchResult != BST->root){
				PRINTF("ERROR: Unexpected Event occured.\n");
				return NULL;
			}
			BST->root = searchResult->left;
			if (searchResult->left != NULL)
				searchResult->left->parent = NULL;
			free(searchResult);
			return BST;
		}
		//When the element is not a root node.
		if (searchResult->parent->right == searchResult){
			searchResult->parent->right = searchResult->left;
			if (searchResult->left != NULL)
				searchResult->left->parent = searchResult->parent;
			free(searchResult);
			return BST;
		}

		if(searchResult->parent->left != searchResult){
			PRINTF("ERROR: Unexpected Event occured.\n");
			return NULL;
		}

		searchResult->parent->left = searchResult->left;
		if (searchResult->left != NULL)
			searchResult->left->parent = searchResult->parent;
		free(searchResult);
		return BST;
	}

	//When element has only a right child.
	if (searchResult->left == NULL){
		//When the element is a root node.
		if (searchResult->parent == NULL){
			//Exception Handling
			if (searchResult != BST->root){
				PRINTF("ERROR: Unexpected Event occured.\n");
				return NULL;
			}
			BST->root = searchResult->right;
			if (searchResult->right != NULL)
				searchResult->right->parent = NULL;
			free(searchResult);
			return BST;
		}
		//When the element is not a root node.
		if (searchResult->parent->right == searchResult){
			searchResult->parent->right = searchResult->right;
			if (searchResult->right != NULL)
				searchResult->right->parent = searchResult->parent;
			free(searchResult);
			return BST;
		}

		if(searchResult->parent->left != searchResult){
			PRINTF("ERROR: Unexpected Event occured.\n");
			return NULL;
		}

		searchResult->parent->left = searchResult->right;
		if (searchResult->right != NULL)
			searchResult->right->parent = searchResult->parent;
		free(searchResult);
		return BST;
	}

	//When element has both left and right children.
	if (searchResult->left == NULL || searchResult->right == NULL){
		PRINTF("ERROR: Unexpected Event occured.\n");
		return NULL;
	}

	InorderPredecessor = searchResult->left;
	while(1){
		if (InorderPredecessor->right == NULL)
			break;
		InorderPredecessor = InorderPredecessor->right;
	}

	searchResult->data = InorderPredecessor->data;
	if (InorderPredecessor->parent->left == InorderPredecessor){
		InorderPredecessor->parent->left = InorderPredecessor->left;
		if (InorderPredecessor->left != NULL)
			InorderPredecessor->left->parent = InorderPredecessor->parent;
	}
	else{
		InorderPredecessor->parent->right = InorderPredecessor->left;
		if (InorderPredecessor->left != NULL)
			InorderPredecessor->left->parent = InorderPredecessor->parent;
	}

	free(InorderPredecessor);

	return BST;
}

SPLAY_BST *PreorderTraversal(SPLAY_BST *BST, DEQUE *outputDeque)
{
	//<SampelBST>
	//         50
	//    20        100
	//   5  35     11 300
	//            60

	//<Sampel outputDeque>
	//(Begin) 50 20 5 35 100 11 60 300 (End)

	DEQUE *DFS_Deque = CreateDeque();
	SPLAY_BST_NODE *current = NULL;

	//Exception Handling1
	if (BST==NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (outputDeque==NULL){
		PRINTF("ERROR: outputDeque is NULL.\n");
		return NULL;
	}

	//When the BST is empty.
	if (BST->root==NULL){
		return BST;
	}
	
	//DFS start.
	current = BST->root;

	while(1){
		//Visit Check.
		if (PushRight(outputDeque, current) != outputDeque){
			PRINTF("current: %p, current->data: %d\n", current, current->data);
			PRINTF("ERROR: PushRight(outputDeque, BST->current) failed.\n");
			return NULL;
		}

		//Try to go left.
		if (current->left != NULL){
			if (PushRight(DFS_Deque, current) != DFS_Deque){
				PRINTF("ERROR: PushRight(DFS_Deque, current) failed.\n");
				return NULL;
			}
			current = current->left;
			continue;
		}

		while(1){
			//When the current->left is NULL.
			//or When the current becomes the most-recent node from the DFS_Stack.
			//Try to go right.
			if (current->right != NULL){
				current = current->right;
				break;
			}

			//When the current->right is NULL.
			if (PopRight(DFS_Deque, &current) == NULL){
				//When the DFS is finished.
				goto DFS_END;
			}
			continue;
		}
	}
DFS_END:
	if (RemoveDeque(DFS_Deque)){
		PRINTF("ERROR: RemoveDeque( ) failed.\n");
		return NULL;
	}

	return BST;
}

SPLAY_BST_NODE *RotateLeft(SPLAY_BST *BST, SPLAY_BST_NODE *node)
{
	SPLAY_BST_NODE *rightnode = NULL;

	//Exception Handling 1.
	if (BST==NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	//Exception Handling 2.
	if (node==NULL){
		PRINTF("ERROR: node is NULL.\n");
		return NULL;
	}

	rightnode = node->right;

	//Exception Handling 3.
	if (rightnode == NULL){
		PRINTF("ERROR: node->right is NULL during the rotating left.\n");
		return NULL;
	}

	//When the node is a root node.
	if (node->parent == NULL){
		BST->root = rightnode;
		rightnode->parent = NULL;
	}

	//When the node is a left child.
	if (node->parent->left == node){
		node->parent->left = rightnode;
		rightnode->parent = node->parent;
	}

	//When the node is a right child.
	if (node->parent->right != node){
		PRINTF("ERROR: Unexpected event occurs.\n");
		return NULL;
	}
	else {
		node->parent->right = rightnode;
		rightnode->parent = node->parent;
	}

	//Placing the left child of right node into right child of current node.
	node->right = rightnode->left;
	if (node->right != NULL)
		node->right->parent = node;

	rightnode->left = node;
	node->parent = rightnode;

	return rightnode;	
}

SPLAY_BST_NODE *RotateRight(SPLAY_BST *BST, SPLAY_BST_NODE *node)
{
	SPLAY_BST_NODE *leftnode = NULL;

	//Exception Handling 1.
	if (BST==NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	//Exception Handling 2.
	if (node==NULL){
		PRINTF("ERROR: node is NULL.\n");
		return NULL;
	}

	leftnode = node->left;

	//Exception Handling 3.
	if (leftnode == NULL){
		PRINTF("ERROR: node->left is NULL during the rotating right.\n");
		return NULL;
	}

	//When the node is a root node.
	if (node->parent == NULL){
		BST->root = leftnode;
		leftnode->parent = NULL;
	}

	//When the node is a left child.
	if (node->parent->left == node){
		node->parent->left = leftnode;
		leftnode->parent = node->parent;
	}

	//When the node is a right child.
	if (node->parent->right != node){
		PRINTF("ERROR: Unexpected event occurs.\n");
		return NULL;
	}
	else {
		node->parent->right = leftnode;
		leftnode->parent = node->parent;
	}

	//Placing the right child of leftnode into left child of current node.
	node->left = leftnode->right;
	if (node->left != NULL)
		node->left->parent = node;

	leftnode->right = node;
	node->parent = leftnode;

	return leftnode;	
}

SPLAY_BST_NODE *Correction(SPLAY_BST *BST, SPLAY_BST_NODE *node)
{
	//Exception Handling1
	if (BST==NULL){
		PRINTF("ERROR: BST is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (node==NULL){
		PRINTF("ERROR: node is NULL.\n");
		return NULL;
	}

	//When the Correction is not needed.
	if (node==BST->root){
		return node;
	}

	//Zig Rotation: When the parent of node is a root.
	if (node->parent == BST->root){
		//When root->left == node
		if (node->parent->left == node){
			if(RotateRight(BST, BST->root) != node){
				PRINTF("ERROR: RotateRight(BST->root) failed during the Zig rotation.\n");
				return NULL;
			}
			return node;
		}
		//When root->right == node
		if (node->parent->right == node){
			if(RotateLeft(BST, BST->root) != node){
				PRINTF("ERROR: RotateLeft(BST->root) failed during the Zig rotation.\n");
				return NULL;
			}
			return node;
		}
	}

	//ZigZig Rotation
	if ((node->parent->left==node && node->parent->parent->left==node->parent)
		|| (node->parent->right==node && node->parent->parent->right==node->parent)){
		
		//When (Grandparent->left->left == node) -> then (RotateRight(GrandParent)x2)
		if (node->parent->left == node){
			if(node->parent != RotateRight(BST, node->parent->parent)){
				PRINTF("ERROR: 1st RotateRight(node->parent->parent) failed during the ZigZig rotation.\n");
				return NULL;
			}
			if(node != RotateRight(BST, node->parent)){
				PRINTF("ERROR: 2nd RotateRight(node->parent) failed during the ZigZig rotation.\n");
				return NULL;
			}
			return node;
		}

		//When (Grandparent->right->right == node) -> then (RotateLeft(GrandParent)x2)
		if (node->parent->right == node){
			if(node->parent != RotateLeft(BST, node->parent->parent)){
				PRINTF("ERROR: 1st RotateLeft(node->parent->parent) failed during the ZigZig rotation.\n");
				return NULL;
			}
			if(node != RotateLeft(BST, node->parent)){
				PRINTF("ERROR: 2nd RotateLeft(node->parent) failed during the ZigZig rotation.\n");
				return NULL;
			}
			return node;
		}
	}

	//ZigZag Rotation
	if ((node->parent->left==node && node->parent->parent->right==node->parent)
		|| (node->parent->right==node && node->parent->parent->left==node->parent)){
		
		//When (Grandparent->left->right == node) -> then (RotateLeft(Parent), RotateRight(GrandParent))
		if (node->parent->right == node){
			if(RotateLeft(BST, node->parent) != node){
				PRINTF("ERROR: 1st RotateLeft(node->parent) failed during the ZigZag rotation.\n");
				return NULL;
			}
			if(RotateRight(BST, node->parent) != node){
				PRINTF("ERROR: 2nd RotateRight(node->parent) failed during the ZigZag rotation.\n");
				return NULL;
			}
			return node;
		}

		//When (Grandparent->right->left == node) -> then (RotateRight(Parent), RotateLeft(GrandParent))
		if (node->parent->left == node){
			if(RotateRight(BST, node->parent) != node){
				PRINTF("ERROR: 1st RotateRight(node->parent) failed during the ZigZag rotation.\n");
				return NULL;
			}
			if(RotateLeft(BST, node->parent) != node){
				PRINTF("ERROR: 2nd RotateLeft(node->parent) failed during the ZigZag rotation.\n");
				return NULL;
			}
			return node;
		}
	}

	//Exception Handling.
	PRINTF("ERROR: Something unexpected situation occured.\n");
	return NULL;
}

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

CIRCULAR_DEQUE *EmptyDeque(CIRCULAR_DEQUE *Deque)
{
	//Exception Handling
	if (Deque == NULL){
		PRINTF("ERROR: Deque is NULL.\n");
		return NULL;
	}

	Deque->begin = -1;
	Deque->end = -1;

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
