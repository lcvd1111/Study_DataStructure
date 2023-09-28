#include "lib_graph.h"

//Function Definitions
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	(*this).matrix = NULL;
	(*this).size = -1;

	//Method Binding
	(*this).CreateGraph = GRAPH_METHOD_CreateGraph;
	(*this).DestroyGraph = GRAPH_METHOD_DestroyGraph;
	(*this).AddEdge_Directed = GRAPH_METHOD_AddEdge_Directed;
	(*this).AddEdge = GRAPH_METHOD_AddEdge;
	(*this).Create_BFS_Buffer = GRAPH_METHOD_Create_BFS_Buffer;
	(*this).Release_BFS_Buffer = GRAPH_METHOD_Release_BFS_Buffer;
	(*this).BFS = GRAPH_METHOD_BFS;
	(*this).Print = GRAPH_METHOD_Print;
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
	if (this->matrix != NULL){
		DEBUG("ERROR: Matrix already exists. Destroy it first.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg is smaller than 1. It must be at least 1.\n");
		return NULL;
	}

	(*this).size = sizeArg;
	(*this).matrix = (char **)malloc(sizeof(char *)*sizeArg);
	for (int i=0; i<sizeArg ; i++){
		((*this).matrix)[i] = (char *)malloc(sizeof(char)*sizeArg);
		for (int j=0 ; j<sizeArg ; j++){
			((*this).matrix)[i][j] = 0;
		}
	}

	return this;
}

GRAPH *GRAPH_METHOD_DestroyGraph(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<(*this).size ; i++){
		free(((*this).matrix)[i]);
	}
	free((*this).matrix);

	(*this).matrix = NULL;
	(*this).size = -1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
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

	(*this).matrix[nodeA][nodeB] = 1;

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
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
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

	(*this).matrix[nodeA][nodeB] = 1;
	(*this).matrix[nodeB][nodeA] = 1;

	return this;
}

int *GRAPH_METHOD_Create_BFS_Buffer(GRAPH *this)
{
	int *ret = NULL;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}
	
	ret = (int *)malloc(sizeof(int)*(*this).size);
	for (int i=0; i<(*this).size ; i++){
		ret[i] = -1;
	}

	return ret;
}

int GRAPH_METHOD_Release_BFS_Buffer(GRAPH *this, int *bufferArg)
{
	//Exception Hnadling
	if(bufferArg == NULL){
		DEBUG("ERROR: bufferArg is NULL.\n");
		return -1;
	}

	free(bufferArg);

	return 0;
}

GRAPH *GRAPH_METHOD_BFS(GRAPH *this, int *resultStore)
{
	char *visitVector = NULL;
	int currentNode = -1;
	int tempNode = -1;
	QUEUE bfs_Queue;
	QUEUE_CONSTRUCTOR(&bfs_Queue);
	int index = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	//Exception Handling3
	if (resultStore == NULL){
		DEBUG("ERROR: resultStore is NULL.\n");
		return NULL;
	}

	//Making visit vector
	visitVector = (char *)malloc(sizeof(char)*(*this).size);
	memset(visitVector, 0, sizeof(char)*(*this).size);

	//Making BFS Queue
	bfs_Queue.CreateQueue(&bfs_Queue, this->size);

	//StartBFS
	currentNode = 0;

	bfs_Queue.Enqueue(&bfs_Queue, currentNode);
	visitVector[currentNode] = 1;

	while(1){
		if (bfs_Queue.Empty(&bfs_Queue)){
			break;
		}

		bfs_Queue.Dequeue(&bfs_Queue, &currentNode);
		visitVector[currentNode] = 2;
		resultStore[index] = currentNode;
		index++;

		for ( tempNode=0; tempNode<(*this).size ; tempNode++){
			if ((*this).matrix[currentNode][tempNode]==1 && visitVector[tempNode]==0){
				bfs_Queue.Enqueue(&bfs_Queue, tempNode);
				visitVector[tempNode] = 1;
			}
		}
	}


	free(visitVector);
	QUEUE_DESTRUCTOR(&bfs_Queue);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<(*this).size ; i++){
		for (int j=0 ; j<(*this).size ; j++){
			printf("%d ", (*this).matrix[i][j]);
		}
		printf("\n");
	}

	return this;
}
