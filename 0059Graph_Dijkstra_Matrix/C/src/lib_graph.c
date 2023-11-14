#include "lib_graph.h"
#include "lib_heap.h"

//Function Declarations
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
	this->Dijkstra = &GRAPH_METHOD_Dijkstra;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	if (this->matrix != NULL){
		(*this).Destroy(this);
		return ;
	}

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
		PRINTF_ERROR("ERROR: 'this->matrix' is not NULL already.\n");
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
		(this->matrix)[i] = (int *)malloc(sizeof(int) * sizeArg);
		for (int j=0 ; j<sizeArg ; j++){
			(this->matrix)[i][j] = 0;
		}
	}

	return NULL;
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
		(this->matrix)[i] = NULL;
	}
	free(this->matrix);
	this->matrix = NULL;
	this->size = 0;

	return NULL;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB, int weight)
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
	if (nodeA >= this->size){
		PRINTF_ERROR("ERROR: nodeA >= size.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		PRINTF_ERROR("ERROR: nodeB >= size.\n");
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = weight;

	return NULL;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB, int weight)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	(*this).AddEdge_Directed(this, nodeA, nodeB, weight);
	(*this).AddEdge_Directed(this, nodeB, nodeA, weight);

	return NULL;
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

	for (int i=0 ; i<(this->size) ; i++){
		for (int j=0 ; j<(this->size) ; j++){
			printf(COLOR_GREEN "%d ", (this->matrix)[i][j]);
		}
		printf("\n");
	}

	printf(COLOR_BLACK);
	return NULL;
}

GRAPH *GRAPH_METHOD_Dijkstra(GRAPH *this)
{
	int currentNode=0, neighborNode=0, successorNode=0;
	int **pMatrix = NULL;
	int *visitVector = NULL, *distanceVector, *successorVector = NULL;
	HEAP_NODE heapNode;
	HEAP dijkstraPQ;
	HEAP_CONSTRUCTOR(&dijkstraPQ);
	int loopCtl = 0;

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

	//Initializing the auxiliary variables and objects.
	pMatrix = this->matrix;
	visitVector = (int *)calloc(this->size, sizeof(int));
	distanceVector = (int *)malloc(sizeof(int) * (this->size));
	for (int i=0 ; i<this->size ; i++){
		distanceVector[i] = 999999;
	}
	successorVector = (int *)malloc(sizeof(int) * (this->size));
	for (int i=0 ; i<this->size ; i++){
		successorVector[i] = -1;
	}
	dijkstraPQ.Create(&dijkstraPQ, this->size);

	//Dijsktra Algorith Start.
	currentNode = 0;
	visitVector[currentNode] = 1;
	distanceVector[currentNode] = 0;

	loopCtl = 1;
	while(loopCtl){
		//Enqueuing every proper neighborhoods of the current node.
		for (neighborNode=0 ; neighborNode<(this->size) ; neighborNode++){
			if (pMatrix[currentNode][neighborNode] == 0){
				continue;
			}
			if (visitVector[neighborNode] == 1){
				continue;
			}
			if (distanceVector[neighborNode] < distanceVector[currentNode] + pMatrix[currentNode][neighborNode])
			{
				continue;
			}
			//Found proper node.
			distanceVector[neighborNode] = distanceVector[currentNode] + pMatrix[currentNode][neighborNode]; //Updating the distance information.
			heapNode.key = distanceVector[neighborNode];
			heapNode.graphCurrentNode = currentNode;
			heapNode.graphNeighborNode = neighborNode;
			dijkstraPQ.Enqueue(&dijkstraPQ, &heapNode); //Enqueueing the data into priority queue.
		}

		//Dequeuing form the Priority queue.
		while(1){
			if (dijkstraPQ.Empty(&dijkstraPQ) == 1){
				loopCtl = 0;
				break;
			}

			dijkstraPQ.Peek(&dijkstraPQ, &heapNode);
			dijkstraPQ.Dequeue(&dijkstraPQ);

			if (visitVector[heapNode.graphNeighborNode] == 1){
				//When the dequeued node is already visited before.
				continue;
			}

			visitVector[heapNode.graphNeighborNode] = 1;
			successorVector[heapNode.graphNeighborNode] = heapNode.graphCurrentNode;
		}
	}

	//Printing the result.
	for (int i=0; i<(this->size) ; i++){
		printf("Distance from %d to %d: %d\n", 0, i, distanceVector[i]);
		int j=i;
		printf("Path: ");
		while (j!=0 && j!=-1){
			printf("%d <- ", j);
			j = successorVector[j];
		}
		printf("0\n");
	}

	//Destroying the auxiliary variables and objects.
	free(visitVector);
	free(distanceVector);
	free(successorVector);
	dijkstraPQ.Destroy(&dijkstraPQ);
	HEAP_DESTRUCTOR(&dijkstraPQ);

	return NULL;
}
