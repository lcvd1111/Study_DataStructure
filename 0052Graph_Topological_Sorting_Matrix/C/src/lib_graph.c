#include "lib_graph.h"

void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->matrix = NULL;
	this->size = -1;

	//Binding Method functions
	this->Create = &GRAPH_METHOD_Create;
	this->Destroy = &GRAPH_METHOD_Destroy;
	this->AddEdge_Directed= &GRAPH_METHOD_AddEdge_Directed;
	this->AddEdge = &GRAPH_METHOD_AddEdge;
	this->Print = &GRAPH_METHOD_Print;
	this->TopologicalSorting = &GRAPH_METHOD_TopologicalSorting;

	return;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->matrix == NULL){
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
		DEBUG("ERROR: sizeArg < 1.\n");
		return NULL;
	}

	//Excetpion Handling3
	if (this->matrix != NULL){
		DEBUG("ERROR: this->matrix is not NULL.\n");
		return NULL;
	}

	this->size = sizeArg;
	(*this).matrix = (int **)malloc(sizeof(int *)*(this->size));
	for (int i=0 ; i<sizeArg ; i++){
		((*this).matrix)[i] = (int *)malloc(sizeof(int)*(this->size));
		for (int j=0 ; j<sizeArg ; j++){
			(this->matrix)[i][j] = 0;
		}
	}

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Excetpion Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		free((this->matrix)[i]);
	}

	free(this->matrix);
	this->matrix = NULL;
	this->size = -1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Excetpion Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (nodeA >= this->size){
		DEBUG("ERROR: nodeA >= size.\n");
		return NULL;
	}

	//Exception Handling4
	if (nodeB >= this->size){
		DEBUG("ERROR: nodeB >= size.\n");
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = 1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Excetpion Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	(*this).AddEdge_Directed(this, nodeA, nodeB);
	(*this).AddEdge_Directed(this, nodeB, nodeA);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Excetpion Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		for (int j=0 ; j<this->size ; j++){
			printf("%d ", (this->matrix)[i][j]);
		}
		printf("\n");
	}

	return this;
}

int CalcIndegree(GRAPH *graphArg, int *indegreeStore)
{
	int currentNode=0, tempNode=0;
	int **pMatrix = graphArg->matrix;

	for (int i=0 ; i<graphArg->size ; i++){
		for (int j=0 ; j<graphArg->size ; j++){
			if (pMatrix[i][j] == 1){
				indegreeStore[j] += 1;
			}
		}
	}

	return 0;
}

GRAPH *GRAPH_METHOD_TopologicalSorting(GRAPH *this, int *outputStore)
{
	QUEUE zeroIndegreeQueue;
	QUEUE *pQueue = &zeroIndegreeQueue;
	QUEUE_CONSTRUCTOR(pQueue);
	int **pMatrix = NULL;

	int *indegreeArray = NULL;
	int currentNode=0, tempNode=0;

	int loopCounter = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Excetpion Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	//Creating auxiliary obejcts.
	zeroIndegreeQueue.Create(pQueue, this->size);
	indegreeArray = (int *)malloc(sizeof(int)*(this->size));
	CalcIndegree(this, indegreeArray);
	pMatrix = this->matrix;

	//Pushing every node whose indgree is 0 to queue.
	for (int i=0 ; i<this->size ; i++){
		if (indegreeArray[i] == 0){
			zeroIndegreeQueue.Enqueue(pQueue, i);
		}
	}

	while(1){
		if (zeroIndegreeQueue.Empty(pQueue) == 1){
			break;
		}
	
		//Dequeueing and visit check.
		zeroIndegreeQueue.Dequeue(pQueue, &currentNode);
		outputStore[loopCounter++] = currentNode;

		//Traversing the successors.
		for (tempNode=0 ; tempNode<this->size ; tempNode++){
			if (pMatrix[currentNode][tempNode] == 0){
				continue;
			}
			indegreeArray[tempNode] -= 1;

			//Enqueueing the successor whose indegree value becomes zero.
			if (indegreeArray[tempNode] == 0){
				zeroIndegreeQueue.Enqueue(pQueue, tempNode);
			}
		}
	}

	free(indegreeArray);
	QUEUE_DESTRUCTOR(pQueue);

	return this;
}
