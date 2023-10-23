#include "lib_graph.h"

void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return ;
	}

	this->matrix = NULL;
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
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
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
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix != NULL){
		DEBUG("ERROR: this->matrix is not NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		DEBUG("ERROR: sizeArg is smaller than 1.\n");
		return NULL;
	}

	(this->matrix) = (int **)malloc(sizeof(int *)*sizeArg);
	for (int i=0 ; i<sizeArg ; i++){
		(this->matrix)[i] = (int *)malloc(sizeof(int)*sizeArg);
		for (int j=0 ; j<sizeArg ; j++){
			(this->matrix)[i][j] = 0;
		}
	}
	this->size = sizeArg;

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<(this->size) ; i++){
		free((this->matrix)[i]);
	}
	free(this->matrix);
	this->matrix = NULL;
	this->size = -1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeA >= (this->size)){
		DEBUG("ERROR: nodeA >= size\n");
		return NULL;
	}

	//Exception Handling
	if (nodeB >= (this->size)){
		DEBUG("ERROR: nodeB >= size\n");
		return NULL;
	}

	(this->matrix)[nodeA][nodeB] = weightArg;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB, int weightArg)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	(this->AddEdge_Directed)(this, nodeA, nodeB, weightArg);
	(this->AddEdge_Directed)(this, nodeB, nodeA, weightArg);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	for (int i=0 ; i<(this->size) ; i++){
		for (int j=0 ; j<(this->size) ; j++){
			printf("%d ", (this->matrix)[i][j]);
		}
		printf("\n");
	}

	return this;
}

int GRAPH_METHOD_Weight(GRAPH *this)
{
	int ret = 0;
	
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return -1;
	}

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return -2;
	}

	for (int i=0 ; i<(this->size) ; i++){
		for (int j=i ; j<(this->size) ; j++){
			ret += (this->matrix)[i][j];
		}
	}

	return ret;
}

GRAPH *GRAPH_METHOD_Prim(GRAPH *this, GRAPH *outputStore)
{
	HEAP primPQ;
	HEAP_CONSTRUCTOR(&primPQ);
	HEAP_NODE pqNodeBuffer;
	char *mstVector = NULL;
	int *distanceVector = NULL;
	int **pMatrix = NULL;
	int currentNode=0, neighbor=0, parentNode=0;
	int loopCtl = 0;

	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->matrix == NULL){
		DEBUG("ERROR: this->matrix is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (outputStore == NULL){
		DEBUG("ERROR: outputStore is NULL.\n");
		return NULL;
	}

	//Clearing and Initializaing the outputStore
	if (outputStore->matrix != NULL){
		(*outputStore).Destroy(outputStore);
	}
	(*outputStore).Create(outputStore, this->size);

	//Initializing the auxiliary objects and variables
	primPQ.Create(&primPQ, 10);
	mstVector = (char *)calloc((this->size), sizeof(char));
	distanceVector = (int *)malloc((this->size)*sizeof(int));
	for (int i=0 ; i<(this->size) ; i++){
		distanceVector[i] = INT_MAX;
	}
	pMatrix = this->matrix;

	//Prim Algorihtm Start
	currentNode = 0;
	parentNode = -1;
	loopCtl = 1;
	while(loopCtl){
		//Current Node MST visit Checking
		if (parentNode != -1){
			outputStore->AddEdge(outputStore, parentNode, currentNode, pMatrix[parentNode][currentNode]);
		}
		mstVector[currentNode] = 1;
		distanceVector[currentNode] = 0;

		//Traversing the neighbors
		for (neighbor = 0 ; neighbor<(this->size) ; neighbor++){
			if (pMatrix[currentNode][neighbor] == 0){
				//When it is not a neighbor
				continue;
			}

			if (mstVector[neighbor] == 1){
				//When the neighbor is already in MST.
				continue;
			}

			if (distanceVector[neighbor] < pMatrix[currentNode][neighbor]){
				//When the shorter connection toward this neighbor is already stored in Priority Queue before.
				continue;
			}

			//New fringe node is found. Updating the distance informations and Enqueueing it to Priority queue.
			distanceVector[neighbor] = pMatrix[currentNode][neighbor];
			pqNodeBuffer.key = pMatrix[currentNode][neighbor];
			pqNodeBuffer.node_id = neighbor;
			pqNodeBuffer.parent_node_id = currentNode;
			primPQ.Enqueue(&primPQ, &pqNodeBuffer);
		}

		//Dequeuing from Priority queue.
		while(1){
			if (primPQ.Empty(&primPQ) == 1){
				loopCtl = 0;
				break;
			}

			primPQ.Dequeue(&primPQ, &pqNodeBuffer);
			if (mstVector[pqNodeBuffer.node_id] == 1){
				//When the dequeued node is already in MST.
				continue;
			}

			//New node to insert into MST is found.
			currentNode = pqNodeBuffer.node_id;
			parentNode = pqNodeBuffer.parent_node_id;
			break;
		}
	}


	//Destroying the auxiliary objects and variables
	primPQ.Destroy(&primPQ);
	HEAP_DESTRUCTOR(&primPQ);
	free(mstVector);
	free(distanceVector);
	return this;
}
