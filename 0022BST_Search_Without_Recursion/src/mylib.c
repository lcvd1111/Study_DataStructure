#include "mylib.h"

//Function Definitions
BINTREE_NODE *SearchBST(BINTREE_NODE *root, int arg)
{
	BINTREE_NODE *current = NULL;

	if (root==NULL){
		PRINTF("ERROR: root is NULL.\n");
		return 0;
	}

	current = root;

	while(1){
		if (current->number > arg){
			if (current->left == NULL)
				return NULL;

			current = current->left;
			continue;
		}
		
		if (current->number < arg){
			if (current->right == NULL)
				return NULL;
			
			current = current->right;
			continue;
		}

		if (current->number == arg){
			return current;
		}

		PRINTF("ERROR: Search went wrong.\n");
		return NULL;
	}
	current = root;
	return 0;
}

BINTREE_NODE *MakeChild
(BINTREE_NODE *parent, CHILD_SELECTOR select,
 int lArg, const char *lArgString, 
 int rArg, const char *rArgString)
{
	if (parent == NULL){
		PRINTF("ERROR: parent is NULL.\n");
		return NULL;
	}

	switch(select){
	case LEFT:
		if (parent->left != NULL){
			PRINTF("ERROR: parent has a left child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));

		parent->left->number = lArg;
		strncpy(parent->left->name, lArgString, NAME_MAX);
		parent->left->left = NULL;
		parent->left->right = NULL;
		break;
	case RIGHT:
		if (parent->right != NULL){
			PRINTF("ERROR: parent has a right child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->right->number = rArg;
		strncpy(parent->right->name, rArgString, NAME_MAX);
		parent->right->left = NULL;
		parent->right->right = NULL;
		break;
	case BOTH:
		if (parent->left != NULL){
			PRINTF("ERROR: parent has a left child.\n");
			return NULL;
		}

		parent->left = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE));
		parent->left->number = lArg;
		strncpy(parent->left->name, lArgString, NAME_MAX);
		parent->left->left = NULL;
		parent->left->right = NULL;
		
		if (parent->right != NULL){
			PRINTF("ERROR: parent has a right child.\n");
			return NULL;
		}

		parent->right = (BINTREE_NODE *)malloc(sizeof(BINTREE_NODE ));
		parent->right->number = rArg;
		strncpy(parent->right->name, rArgString, NAME_MAX);
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
