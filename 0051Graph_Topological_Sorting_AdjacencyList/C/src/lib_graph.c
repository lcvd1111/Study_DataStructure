#include "lib_graph.h"

//Function Definitions
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->nodeArray = NULL;
	this->size = -1;

	//Binding Method functions
	(*this).Create = &GRAPH_METHOD_Create;
	(*this).Destroy = &GRAPH_METHOD_Destroy;
	(*this).AddEdge_Directed = &GRAPH_METHOD_AddEdge_Directed;
	(*this).AddEdge = &GRAPH_METHOD_AddEdge;
	(*this).Print = &GRAPH_METHOD_Print;
	(*this).TopologicalSort = &GRAPH_METHOD_TopologicalSort;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

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
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg <= 1");
		return NULL;
	}

	//Exception Handling3
	if (this->nodeArray != NULL){
		DEBUG("ERROR: this->nodeArray is not NULL.\n");
		return NULL;
	}

	(*this).nodeArray = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE)*sizeArg);
	(*this).size = sizeArg;

	for (int i=0 ; i<sizeArg ; i++){
		(this->nodeArray)[i].node_id = i;
		(this->nodeArray)[i].prev = NULL;
		(this->nodeArray)[i].next = NULL;
	}

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	GRAPH_NODE *currentNode = NULL;
	GRAPH_NODE *tempNode = NULL;
	GRAPH_NODE *tempNode2 = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		currentNode = (this->nodeArray) + i;
		tempNode = currentNode->next;
		while(tempNode != NULL){
			tempNode2 = tempNode->next;
			free(tempNode);
			tempNode = tempNode2;
		}
	}

	free(this->nodeArray);
	
	this->nodeArray = NULL;
	this->size = -1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB)
{
	GRAPH_NODE *currentNode = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
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
	if (nodeB >= this->size){
		DEBUG("ERROR: nodeB >= size\n");
		return NULL;
	}

	currentNode = (this->nodeArray) + nodeA;
	while (currentNode->next != NULL){
		currentNode = currentNode->next;
	}

	if (currentNode->next != NULL){
		DEBUG("ERROR: Unexpected Situation Occured.\n");
		return NULL;
	}
	
	currentNode->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	currentNode->next->prev = currentNode;
	currentNode->next->next = NULL;
	currentNode->next->node_id = nodeB;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	(this->AddEdge_Directed)(this, nodeA, nodeB);
	(this->AddEdge_Directed)(this, nodeB, nodeA);

	return NULL;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	GRAPH_NODE *currentNode;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		currentNode = (this->nodeArray)+i;
		printf("[Node]: %d [Edge]: ", currentNode->node_id);
		currentNode = currentNode->next;
		while (currentNode != NULL){
			printf("%d ", currentNode->node_id);
			currentNode = currentNode->next;
		}
		printf("\n");
	}

	return this;
}

int CalcIndegree(GRAPH *graphArg, int *indegreeArrayArg)
{
	GRAPH_NODE *currentNode=NULL, *tempNode=NULL;
	GRAPH_NODE *pNodeArray = graphArg->nodeArray;

	for (int i=0 ; i<graphArg->size ; i++){
		currentNode = pNodeArray+i;
		tempNode = currentNode->next;
		while(tempNode != NULL){
			indegreeArrayArg[tempNode->node_id] += 1;
			tempNode = tempNode->next;
		}
	}

	return 0;
}

GRAPH *GRAPH_METHOD_TopologicalSort(GRAPH *this, int *outputStorage)
{
	int *indegreeArray = NULL;
	GRAPH_NODE *currentNode=NULL, *tempNode = NULL;
	GRAPH_NODE *pNodeArray = NULL;
	QUEUE zeroIndegreeQueue;
	QUEUE_CONSTRUCTOR(&zeroIndegreeQueue);
	int loopCounter = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->nodeArray == NULL){
		DEBUG("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (outputStorage == NULL){
		DEBUG("ERROR: outputStorage is NULL.\n");
		return NULL;
	}

	pNodeArray = this->nodeArray;

	//Creating indegree Array.
	indegreeArray = (int *)malloc(sizeof(int)*(this->size));
	memset(indegreeArray,0,sizeof(int)*(this->size));

	if (CalcIndegree(this, indegreeArray)){
		DEBUG("ERROR: CalcIndegree( ) failed.\n");
		return NULL;
	}

	//Starting topological sorting.
	for (int i=0 ; i<this->size ; i++){
		if (indegreeArray[i] == 0){
			zeroIndegreeQueue.Enqueue(&zeroIndegreeQueue, (void *)(pNodeArray+i));
		}
	}

	if (zeroIndegreeQueue.Empty(&zeroIndegreeQueue) == 1){
		return NULL;
	}

	while(1){
		if (zeroIndegreeQueue.Empty(&zeroIndegreeQueue) == 1){
			break;
		}

		//Dequeue and visit Check.
		zeroIndegreeQueue.Dequeue(&zeroIndegreeQueue, (void **)(&currentNode));
		outputStorage[loopCounter++] = currentNode->node_id;
		tempNode = currentNode->next;
		while(tempNode != NULL){
			//Decreasing the indegree value of every successors.
			indegreeArray[tempNode->node_id] -= 1;
			//Enqueing the successor if its indegree becomes zero.
			if (indegreeArray[tempNode->node_id] == 0){
				zeroIndegreeQueue.Enqueue(&zeroIndegreeQueue, (void *)(pNodeArray+(tempNode->node_id)));
			}
			tempNode = tempNode->next;
		}
	}

	//Destroying indegree Array.
	free(indegreeArray);
	QUEUE_DESTRUCTOR(&zeroIndegreeQueue);

	return this;
}
