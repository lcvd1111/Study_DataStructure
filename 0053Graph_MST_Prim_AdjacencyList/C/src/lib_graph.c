#include "lib_graph.h"

//Function Definitions
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	this->nodeArray = NULL;
	this->size = -1;

	//Binding Method Functions
	this->Create = &GRAPH_METHOD_Create;
	this->Destroy = &GRAPH_METHOD_Destroy;
	this->AddEdge_Directed = &GRAPH_METHOD_AddEdge_Directed;
	this->AddEdge = &GRAPH_METHOD_AddEdge;
	this->Print = &GRAPH_METHOD_Print;
	this->Weight = &GRAPH_METHOD_Weight;
	this->Prim = &GRAPH_METHOD_Prim;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	if (this->nodeArray == NULL){
		return ;
	}

	(*this).Destroy(this);
	return ;
}

GRAPH *GRAPH_METHOD_Create(GRAPH *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray != NULL){
		DEBUG("ERROR: this->nodeArray is not NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg < 1.\n");
		return NULL;
	}

	this->size = sizeArg;
	this->nodeArray = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE)*sizeArg);

	for (int i=0 ; i<sizeArg ; i++){
		(this->nodeArray)[i].node_id = i;
		(this->nodeArray)[i].weight = 0;
		(this->nodeArray)[i].prev = NULL; 
		(this->nodeArray)[i].next = NULL;
	}

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	GRAPH_NODE *currentNode=NULL, *tempNode=NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		currentNode = (this->nodeArray)+i;
		tempNode = currentNode->next;
		while(tempNode != NULL){
			currentNode = tempNode;
			tempNode = currentNode->next;
			free(currentNode);
		}
	}

	free(this->nodeArray);

	this->nodeArray = NULL;
	this->size = -1;
	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB, int weightArg)
{
	GRAPH_NODE *currentNode=NULL, *tempNode=NULL;
	GRAPH_NODE *pNodeArray = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (nodeA >= this->size){
		DEBUG("ERROR: nodeA >= size\n");
		return NULL;
	}

	//Exception Handling4
	if (nodeA >= this->size){
		DEBUG("ERROR: nodeB >= size\n");
		return NULL;
	}

	pNodeArray = this->nodeArray;

	currentNode = pNodeArray+nodeA;
	tempNode = currentNode->next;

	while(tempNode != NULL){
		currentNode = tempNode;
		tempNode = currentNode->next;
	}

	currentNode->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	currentNode->next->prev = currentNode;
	currentNode->next->next = NULL;
	currentNode->next->node_id = nodeB;
	currentNode->next->weight = weightArg;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	(*this).AddEdge_Directed(this, nodeA, nodeB, weightArg);
	(*this).AddEdge_Directed(this, nodeB, nodeA, weightArg);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	GRAPH_NODE *pNodeArray = NULL;
	GRAPH_NODE *tempNode = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	pNodeArray = this->nodeArray;

	for (int i=0 ; i<this->size ; i++){
		printf("[Node]: %d [Edge, Weight]: ", pNodeArray[i].node_id);
		tempNode = pNodeArray[i].next;
		while(tempNode != NULL){
			printf("(%d,%d) ", tempNode->node_id, tempNode->weight);
			tempNode = tempNode->next;
		}
		printf("\n");
	}

	return this;
}

int GRAPH_METHOD_Weight(GRAPH *this)
{
	int ret = 0;
	GRAPH_NODE *pNodeArray = NULL;
	GRAPH_NODE *currentNode=NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return -2;
	}

	pNodeArray = this->nodeArray;

	//Calculating the Weight.
	for (int i=0 ; i<this->size ; i++){
		currentNode = pNodeArray+i;
		while(currentNode != NULL){
			ret += currentNode->weight;
			currentNode = currentNode->next;
		}
	}

	ret = ret/2;

	return ret;
}

GRAPH *GRAPH_METHOD_Prim(GRAPH *this, GRAPH *outputStore)
{
	HEAP primHeap;
	HEAP_CONSTRUCTOR(&primHeap);
	HEAP_NODE heapBufferNode;
	char *mstVector = NULL;
	int *distanceVector = NULL;
	GRAPH_NODE *currentNode=NULL, *neighbor=NULL, *parentNode=NULL;
	int parentNode_id = 0;
	GRAPH_NODE *pNodeArray = NULL;
	int loopCtl = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (outputStore == NULL){
		DEBUG("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//Clearing and Initializing the outputStore
	if (outputStore->nodeArray != NULL){
		(outputStore->Destroy)(outputStore);
	}
	(outputStore->Create)(outputStore, this->size);

	//Initializing the auxiliary variables and objects
	primHeap.Create(&primHeap, 10);
	mstVector = (char *)calloc(this->size, sizeof(char));
	distanceVector = (int *)malloc((this->size) * sizeof(int));
	for (int i=0 ; i<this->size ; i++){
		distanceVector[i] = INT_MAX;
	}
	pNodeArray = this->nodeArray;

	//Start MST.
	parentNode_id = -1;
	currentNode = pNodeArray+0;

	loopCtl = 1;
	while(loopCtl){
		//CurrentNode MST visit check.
		if (parentNode_id != -1){
			(outputStore->AddEdge)(outputStore,
									parentNode_id,
									currentNode->node_id,
									currentNode->weight);
		}
		mstVector[currentNode->node_id] = 1;
		distanceVector[currentNode->node_id] = 0;

		//Traversing the neighborhood.
		neighbor = (pNodeArray[currentNode->node_id]).next;
		while(neighbor != NULL){
			if (mstVector[neighbor->node_id] == 1){
				//When the neighbor is already in the MST.
				neighbor = neighbor->next;
				continue; 
			}

			if (distanceVector[neighbor->node_id] <= neighbor->weight){
				//When the shorter connection toward the neighbor is already stored before.
				neighbor = neighbor->next;
				continue;
			}

			//Distance information update and Enqueueing to Priority queue.
			distanceVector[neighbor->node_id] = neighbor->weight;
			heapBufferNode.key = neighbor->weight;
			heapBufferNode.data = neighbor;
			primHeap.Enqueue(&primHeap, &heapBufferNode);
			
			neighbor = neighbor->next;
		}
		
		while(1){
			if (primHeap.Empty(&primHeap) == 1){
				loopCtl = 0;
				break;
			}

			primHeap.Dequeue(&primHeap, &heapBufferNode);

			if (mstVector[((GRAPH_NODE *)(heapBufferNode.data))->node_id] == 1){
				continue;
			}

			currentNode = heapBufferNode.data;
			parentNode = currentNode;
			while(parentNode->prev != NULL){
				parentNode = parentNode->prev;
			}
			parentNode_id = parentNode->node_id;
			break;
		}
	}

	//Destroying the auxiliary variables and objects
	primHeap.Destroy(&primHeap);
	HEAP_DESTRUCTOR(&primHeap);
	free(mstVector);
	free(distanceVector);

	return this;
}
