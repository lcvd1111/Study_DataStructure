#include "lib_graph.h"
#include "lib_unionfind.h"
#include "lib_heap.h"

//Function Definitions
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->matrix = NULL;
	this->size = 0;

	//Binding Method Functions
	this->Create = &GRAPH_METHOD_Create;
	this->Destroy = &GRAPH_METHOD_Destroy;
	this->AddEdge_Directed = &GRAPH_METHOD_AddEdge_Directed;
	this->AddEdge = &GRAPH_METHOD_AddEdge;
	this->Print = &GRAPH_METHOD_Print;
	this->Kruskal = &GRAPH_METHOD_Kruskal;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
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
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix != NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is already not NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		PRINTF_ERROR("ERROR: sizeArg < 1.\n");
		return NULL;
	}

	this->size = sizeArg;
	this->matrix = (int **)malloc(sizeof(int *) * sizeArg);
	for (int i=0 ; i<sizeArg ; i++){
		(this->matrix)[i] = (int *)calloc(sizeArg, sizeof(int));
	}

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is already NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<(this->size) ; i++){
		free((this->matrix)[i]);
	}
	free(this->matrix);
	this->matrix = NULL;
	this->size = 0;

	return this;
}

GRAPH 
*GRAPH_METHOD_AddEdge_Directed
(GRAPH *this, int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeA >= (this->size)){
		PRINTF_ERROR("ERROR: nodeA >= size.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeB >= (this->size)){
		PRINTF_ERROR("ERROR: nodeB >= size.\n");
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = weightArg;

	return this;
}

GRAPH 
*GRAPH_METHOD_AddEdge
(GRAPH *this, int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	(*this).AddEdge_Directed(this, nodeA, nodeB, weightArg);
	(*this).AddEdge_Directed(this, nodeB, nodeA, weightArg);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		for (int j=0 ; j<this->size ; j++){
			printf(COLOR_CYAN "%d ", (this->matrix)[i][j]);
		}
		printf("\n");
	}

	printf(COLOR_BLACK);

	return this;
}

GRAPH *GRAPH_METHOD_Kruskal(GRAPH *this, GRAPH *outputStore)
{
	int **pMatrix = NULL;
	int currentNode=0, tmpNode=0;
	HEAP kruskalPQ;
	HEAP_NODE heapNode;
	UNION_FIND kruskalUF;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		PRINTF_ERROR("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (outputStore == NULL){
		PRINTF_ERROR("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//Initializing auxiliary objects.
	pMatrix = this->matrix;
	HEAP_CONSTRUCTOR(&kruskalPQ);
	kruskalPQ.Create(&kruskalPQ, this->size);
	UNION_FIND_CONSTRUCTOR(&kruskalUF);
	kruskalUF.Create(&kruskalUF, this->size);
	if (outputStore->matrix != NULL){
		(*outputStore).Destroy(outputStore);
	}
	(*outputStore).Create(outputStore, this->size);

	//Enqueueing every edge into PriorityQueue
	for (currentNode=0 ; currentNode<(this->size) ; currentNode++){
		for (tmpNode = currentNode ; tmpNode<(this->size) ; tmpNode++){
			if (pMatrix[currentNode][tmpNode] == 0){
				//When there is no edge between c and t.
				continue;
			}
			//When there is a edge between c and t.
			heapNode.key = pMatrix[currentNode][tmpNode];
			heapNode.graphNodeX = currentNode;
			heapNode.graphNodeY = tmpNode;
			kruskalPQ.Enqueue(&kruskalPQ, &heapNode);
		}
	}

	//Dequeuing every edge from PriorityQueue
	while (!(kruskalPQ.Empty(&kruskalPQ))){
		kruskalPQ.Peek(&kruskalPQ, &heapNode);
		kruskalPQ.Dequeue(&kruskalPQ);
		if (kruskalUF.Unite(&kruskalUF, heapNode.graphNodeX, heapNode.graphNodeY) == NULL){
			continue;
		}
		else {
			(*outputStore).AddEdge(outputStore,
								heapNode.graphNodeX,
								heapNode.graphNodeY,
								heapNode.key);
			continue;
		}
	}

	//Destroying the auxiliary objects.
	kruskalPQ.Destroy(&kruskalPQ);
	kruskalUF.Destroy(&kruskalUF);
	HEAP_DESTRUCTOR(&kruskalPQ);
	UNION_FIND_DESTRUCTOR(&kruskalUF);

	return this;
}

