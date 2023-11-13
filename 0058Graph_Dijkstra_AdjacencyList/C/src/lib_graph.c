#include "lib_graph.h"

//Function Definitions
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return ;
	}

	this->nodeVector = NULL;
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

	if (this->nodeVector == NULL){
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
	if (this->nodeVector != NULL){
		PRINTF_ERROR("ERROR: 'this->nodeVector' is already not NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		PRINTF_ERROR("ERROR: 'sizeArg' < 1.\n");
		return NULL;
	}

	this->size = sizeArg;
	this->nodeVector = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE)*sizeArg);
	for (int i=0 ; i<sizeArg ; i++){
		(this->nodeVector)[i].node_id = i;
		(this->nodeVector)[i].weight = 0;
		(this->nodeVector)[i].prev = NULL;
		(this->nodeVector)[i].next = NULL;
	}

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	GRAPH_NODE *tmpNode=NULL, *tmpNode_Next=NULL;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->nodeVector == NULL){
		PRINTF_ERROR("ERROR: 'this->nodeVector' is already NULL.\n");
		return NULL;
	}
	for (int i=0 ; i<(this->size) ; i++){
		tmpNode = ((this->nodeVector)+i)->next;
		while(tmpNode != NULL){
			tmpNode_Next = tmpNode->next;
			free(tmpNode);
			tmpNode = tmpNode_Next;
		}
	}

	free(this->nodeVector);
	this->nodeVector = NULL;
	this->size = 0;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB, int weightArg)
{
	GRAPH_NODE *tmpNode=NULL;

	//Exception Handling
	if (this==NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->nodeVector == NULL){
		PRINTF_ERROR("ERROR: 'this->nodeVector' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeA >= this->size){
		PRINTF_ERROR("ERROR: 'nodeA' >= size.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		PRINTF_ERROR("ERROR: 'nodeB' >= size.\n");
		return NULL;
	}

	tmpNode = (this->nodeVector) + nodeA;
	while(tmpNode->next != NULL){
		tmpNode = tmpNode->next;
	}

	tmpNode->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	tmpNode->next->prev = tmpNode;
	tmpNode->next->next = NULL;
	tmpNode->next->node_id = nodeB;
	tmpNode->next->weight = weightArg;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB, int weightArg)
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
	GRAPH_NODE *tmpNode = NULL;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->nodeVector == NULL){
		PRINTF_ERROR("ERROR: 'this->nodeVector' is NULL.\n");
	}

	for (int i=0 ; i<(this->size) ; i++){
		tmpNode = (this->nodeVector)+i;
		printf(COLOR_BLACK "[Node]: " COLOR_GREEN "%d " COLOR_BLACK "[Neighbor]: ", tmpNode->node_id);
		tmpNode = tmpNode->next;
		while(tmpNode!=NULL){
			printf(COLOR_GREEN "(%d, %d) ", tmpNode->node_id, tmpNode->weight);
			tmpNode = tmpNode->next;
		}
		printf(COLOR_BLACK "\n");
	}

	return this;
}

GRAPH *GRAPH_METHOD_Dijkstra(GRAPH *this)
{
	GRAPH_NODE *currentNode=NULL, *neighborNode=NULL;
	GRAPH_NODE *pNodeVector = NULL;
	int currentIndex=0, successorIndex=0;
	HEAP dijkstraPQ;
	HEAP_CONSTRUCTOR(&dijkstraPQ);
	HEAP_NODE heapNode;
	int *visitVector=NULL, *distanceVector=NULL, *successorVector=NULL;
	int loopCtl = 0;

	//Exception Handling.
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling.
	if (this->nodeVector == NULL){
		PRINTF_ERROR("ERROR: 'this->nodeVector' is NULL.\n");
	}

	//Initializing the auxiliary variables and objects.
	pNodeVector = this->nodeVector;
	dijkstraPQ.Create(&dijkstraPQ, this->size);
	visitVector = (int *)calloc((this->size), sizeof(int));
	distanceVector = (int *)malloc(sizeof(int) * (this->size));
	successorVector = (int *)malloc(sizeof(int) * (this->size));
	for (int i=0 ; i<(this->size) ; i++){
		distanceVector[i] = 99999;
		successorVector[i] = -1;
	}

	//Dijkstra Algorithm Starts.
	currentNode = pNodeVector+0;
	visitVector[currentNode->node_id] = 1;
	distanceVector[currentNode->node_id] = 0;

	loopCtl = 1;
	while(loopCtl){
		neighborNode = currentNode->next;
		//Enqueuing every proper neighborhoods
		while(neighborNode != NULL){
			if (visitVector[neighborNode->node_id] == 1){
				neighborNode = neighborNode->next;
				continue;
			}
			if (distanceVector[currentNode->node_id] + (neighborNode->weight)
				> distanceVector[neighborNode->node_id])
			{
				neighborNode = neighborNode->next;
				continue;
			}
			//Found proper neighborhood to enqueue into Priority queue.
			distanceVector[neighborNode->node_id]
				= distanceVector[currentNode->node_id] + (neighborNode->weight); //Updating Distance Information.
			heapNode.key = neighborNode->weight;
			heapNode.graphCurrentNode = currentNode->node_id;
			heapNode.graphNeighborNode = neighborNode->node_id;
			dijkstraPQ.Enqueue(&dijkstraPQ, &heapNode); //Enqueueing neighborhood to priority queue.
			neighborNode = neighborNode->next;
			continue;
		}

		//Dequeueing from priority queue.
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
			else {
				//Visit check.
				visitVector[heapNode.graphNeighborNode] = 1;
				successorVector[heapNode.graphNeighborNode] = heapNode.graphCurrentNode;
				currentNode = pNodeVector + (heapNode.graphNeighborNode);
				break;
			}
		}
	}

	//Printing the result.
	for (int i=0; i<(this->size) ; i++){
		printf(COLOR_BLACK "Distance from %d to %d: %d\n", 0, i, distanceVector[i]);
		int j = i;
		printf("Path: ");
		while(j != 0 ){
			printf("%d <- ", j);
			j = successorVector[j];
		}
		printf("0\n");
	}

	//Destroying the auxiliary variables and objects.
	dijkstraPQ.Destroy(&dijkstraPQ);
	HEAP_DESTRUCTOR(&dijkstraPQ);
	free(visitVector);
	free(distanceVector);
	free(successorVector);

	return this;
}
