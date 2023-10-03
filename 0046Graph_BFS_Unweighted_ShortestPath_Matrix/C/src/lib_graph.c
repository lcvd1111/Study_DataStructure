#include "lib_graph.h"

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Hadnling
	if (this==NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->matrix = NULL;
	this->size = -1;

	//Binding Method functions
	this->Create = GRAPH_METHOD_Create;
	this->Destroy = GRAPH_METHOD_Destroy;
	this->AddEdge_Directed = GRAPH_METHOD_AddEdge_Directed;
	this->AddEdge = GRAPH_METHOD_AddEdge;
	this->Print = GRAPH_METHOD_Print;
	this->BFS_ShortestPath = GRAPH_METHOD_BFS_ShortestPath;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Hadnling
	if (this==NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->matrix == NULL){
		return ;
	}

	(*this).Destroy(this);

	return ;
}

GRAPH *GRAPH_METHOD_Create(GRAPH * this, int sizeArg)
{
	//Exception Hadnling
	if (this==NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix != NULL){
		DEBUG("ERROR: 'this->matrix' is not NULL.\n");
		return NULL;
	}

	this->size = sizeArg;
	this->matrix = (int **)malloc(sizeof(int *)*sizeArg);
	for (int i=0 ; i<sizeArg ; i++){
		(*this).matrix[i] = (int *)malloc(sizeof(int)*sizeArg);
		for (int j=0 ; j<sizeArg ; j++){
			(*this).matrix[i][j] = 0;
		}
	}

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	//Exception Hadnling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	for (int i=0; i<this->size ; i++){
		free((*this).matrix[i]);
	}
	free((*this).matrix);

	this->matrix = NULL;
	this->size = -1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB)
{
	//Exception Hadnling
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
	//Exception Hadnling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	(*this).AddEdge_Directed(this, nodeA, nodeB);
	(*this).AddEdge_Directed(this, nodeB, nodeA);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	//Exception Hadnling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<this->size ; i++){
		for (int j=0 ; j<this->size ; j++){
			printf("%d ", (*this).matrix[i][j]);
		}
		printf("\n");
	}

	return this;
}

int GRAPH_METHOD_BFS_ShortestPath(GRAPH *this, int *pathOutput, int nodeA, int nodeB)
{
	int ret = -1;
	int currentNode = -1;
	int tempNode = -1;
	char *visitVector = NULL;
	int *departureVector = NULL;
	int **pMatrix = NULL;
	int loopCtl;
	QUEUE bfs_Queue;
	QUEUE_CONSTRUCTOR(&bfs_Queue);

	//Exception Hadnling
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return -1;
	}

	//Exception Handling2
	if (this->matrix == NULL){
		DEBUG("ERROR: 'this->matrix' is NULL.\n");
		return -2;
	}

	//Exception Hnadling3
	if (nodeA >= this->size){
		DEBUG("ERROR: nodeA >= size.\n");
		return -3;
	}

	//Exception Hnadling3
	if (nodeB >= this->size){
		DEBUG("ERROR: nodeB >= size.\n");
		return -4;
	}

	pMatrix = this->matrix;

	//Creatting visitVector and depatureVector and queue
	bfs_Queue.Create(&bfs_Queue, this->size);
	visitVector = (char *)malloc(sizeof(char)*(this->size));
	memset(visitVector, 0, sizeof(char)*(this->size));
	departureVector = (int *)malloc(sizeof(int)*(this->size));
	for (int i=0 ; i<this->size ; i++){
		departureVector[i] = -1;
	}

	//Clearing output path
	for (int i=0; i<this->size ; i++){
		pathOutput[i] = -1;
	}

	//BFS start.
	currentNode = nodeA;

	bfs_Queue.Enqueue(&bfs_Queue, currentNode);
	visitVector[currentNode] = 1;
	departureVector[currentNode] = -1;

	loopCtl = 1;
	while(loopCtl){
		if (bfs_Queue.Empty(&bfs_Queue)){
			ret = -1;
			break;
		}

		//VisitCheck.
		bfs_Queue.Dequeue(&bfs_Queue, &currentNode);
		visitVector[currentNode] =2;
		
		//Traversing neighborhoods.
		tempNode = 0;
		for ( ; tempNode < this->size ; tempNode++){
			if (pMatrix[currentNode][tempNode]==0){
				continue;
			}

			if (pMatrix[currentNode][tempNode]==1 && visitVector[tempNode] != 0){
				//When the neighbor is already visited or stored in queue.
				continue;
			}

			if (pMatrix[currentNode][tempNode]==1 && visitVector[tempNode] == 0){
				//Enqueueing an unvisited neighbor.
				bfs_Queue.Enqueue(&bfs_Queue, tempNode);
				visitVector[tempNode] = 1;
				departureVector[tempNode] = currentNode;

				//When the destination is found.
				if (tempNode == nodeB){
					ret = CalcPath(nodeA, nodeB, departureVector, pathOutput);
					loopCtl = 0;
					break;
				}
			}
		}
	}

	//Destroying visitVector, departureVector and queue
	QUEUE_DESTRUCTOR(&bfs_Queue);
	free(visitVector);
	free(departureVector);

	return ret;
}

int CalcPath(int nodeA, int nodeB, int *departureVector, int *pathOutput)
{
	int length = 0;
	int tempNode = nodeB;

	while(tempNode != nodeA){
		pathOutput[length] = tempNode;
		tempNode = departureVector[tempNode];
		length++;
	}

	pathOutput[length] = tempNode; //Inserting 'nodeA' to pathOutput

	return length;
}
