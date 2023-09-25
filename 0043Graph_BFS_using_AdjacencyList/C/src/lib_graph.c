#include "lib_graph.h"

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling1
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return;
	}

	(*this).nodeArray = NULL;
	(*this).size = -1;

	(*this).CreateGraph = GRAPH_METHOD_CreateGraph;
	(*this).DestroyGraph = GRAPH_METHOD_DestroyGraph;
	(*this).AddEdge_Directed = GRAPH_METHOD_AddEdge_Directed;
	(*this).AddEdge = GRAPH_METHOD_AddEdge;
	(*this).Create_BFS_Buffer = GRAPH_METHOD_Create_BFS_Buffer;
	(*this).Release_BFS_Buffer = GRAPH_METHOD_Release_BFS_Buffer;
	(*this).BFS = GRAPH_METHOD_BFS;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling.
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	//When the nodeArray is not created yet.
	if (this->nodeArray == NULL){
		return ;
	}

	//When the nodeArray is Created.
	(*this).DestroyGraph(this);

	return ;
}

GRAPH *GRAPH_METHOD_CreateGraph(GRAPH *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if ((*this).size < 1){
		DEBUG("ERROR: sizeArg < 1. It must be at least 1.\n");
		return NULL;
	}

	//When the Graph is already created.
	if ((*this).nodeArray != NULL){
		return NULL;
	}

	(*this).size = sizeArg;
	(*this).nodeArray = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE) * sizeArg);

	for (int i=0 ; i<sizeArg ; i++){
		((*this).nodeArray)[i].node_id = i;
		((*this).nodeArray)[i].prev = NULL;
		((*this).nodeArray)[i].next = NULL;
	}

	return this;
}

GRAPH *GRAPH_METHOD_DestroyGraph(GRAPH *this)
{
	GRAPH_NODE *tempNode = NULL;

	//Exception Handling.
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//When the nodeArray is not created yet.
	if (this->nodeArray == NULL){
		return NULL;
	}

	//When the nodeArray is created.
	for (int i=0; i<(*this).size ; i++){
		tempNode  = (*this).nodeArray + i;
		if (tempNode->node_id != i){
			//Exception Handling
			DEBUG("ERROR: Unexpected situation occured.\n");
			return NULL;
		}

		if (tempNode->next == NULL){
			//Pasing the first element of the each linked list.
			continue;
		}

		//Clearing the edge lists.
		tempNode = tempNode->next;

		while(1){
			if (tempNode->next == NULL){
				//When the tempNode is a end node of the linked list.
				free(tempNode);
				tempNode = NULL;
				break;
			}
			tempNode = tempNode->next;
			free(tempNode->prev);
		}
	}

	free((*this).nodeArray);

	(*this).nodeArray = NULL;
	(*this).size = -1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB)
{
	GRAPH_NODE *tempNode = NULL;

	//Exception Handling1.
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2.
	if (this->nodeArray == NULL){
		DEBUG("ERROR: 'this->nodeArray' is NULL. You should create the Graph designating the number of nodes first.\n");
		return NULL;
	}

	//Exception Handling3.
	if (nodeA >= this->size){
		DEBUG("ERROR: nodeA_index >= this->size\n");
		return NULL;
	}
	
	//Exception Handling3.
	if (nodeB >= this->size){
		DEBUG("ERROR: nodeB_index >= this->size\n");
		return NULL;
	}

	tempNode = (*this).nodeArray + nodeA;
	while (tempNode->next != NULL){ 
		//Finding the last node of the linked list.
		tempNode = tempNode->next;
	}

	if (tempNode->next != NULL){
		//Exception Handling.
		DEBUG("ERROR: Unexpected Situation Occured.\n");
		return NULL;
	}

	tempNode->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	tempNode->next->prev = tempNode;
	tempNode->next->next = NULL;
	tempNode->node_id = nodeB;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB)
{
	if(GRAPH_METHOD_AddEdge_Directed(this, nodeA, nodeB) == NULL){
		DEBUG("ERROR: Adding Edge(%d->%d) Failed.\n", nodeA, nodeB);
		return NULL;
	}

	if(GRAPH_METHOD_AddEdge_Directed(this, nodeB, nodeA) == NULL){
		DEBUG("ERROR: Adding Edge(%d->%d) Failed.\n", nodeB, nodeA);
		return NULL;
	}

	return this;
}

int *GRAPH_METHOD_Create_BFS_Buffer(GRAPH *this)
{
	int *ret = NULL;

	//Exception Handling1.
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2.
	if (this->nodeArray == NULL){
		DEBUG("RROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	ret = (int *)malloc(sizeof(int)*(this->size));
	for (int i=0; i<(this->size) ; i++){
		ret[i] = -1;
	}
	
	return ret;
}

int GRAPH_METHOD_Release_BFS_Buffer(GRAPH *this, int *bufferArg)
{
	//Exception Handling
	if (this==NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (bufferArg == NULL){
		DEBUG("ERROR: bufferArg is NULL.\n");
		return -2;
	}

	free(bufferArg);
	return 0;
}

GRAPH *GRAPH_METHOD_BFS(GRAPH *this, int *resultStore)
{
	QUEUE bfsQueue;
	QUEUE *self = &bfsQueue;
	QUEUE_CONSTRUCTOR(self);
	char *visitVector = NULL;
	GRAPH_NODE *currentNode = NULL;

	//Exception Handling.
	if (this == NULL){
		DEBUG("ERROR:, 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2.
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL. Create the graph first.\n");
		return NULL;
	}

	//Exception Handling3.
	if (resultStore == NULL){
		DEBUG("ERROR: resultStore is NULL. Create the BFS Buffer First.\n");
		return NULL;
	}

	//Creating the Queue with enough size. It is used for BFS.
	if (bfsQueue.CreateQueue(self, this->size) == NULL){
		DEBUG("ERROR: Creating bfsQueue(%d) failed.\n", this->size);
		return NULL;
	}

	//Creating the visit vector.
	visitVector = (char *)malloc(sizeof(char) * (this->size));
	memset(visitVector, 0, sizeof(char)*(this->size)); //If the node is enqueued->becomes 1. If the node is dequeued->becomes 2.

	//BFS Start.
	currentNode = this->nodeArray;

	while(1){
	}

	//Destroying the created Queue.
	if (bfsQueue.DestroyQueue(self) == NULL){
		DEBUG("ERROR: Destroying bfsQueue failed.\n");
		return NULL;
	}
	QUEUE_DESTRUCTOR(self);
	return this;
}

