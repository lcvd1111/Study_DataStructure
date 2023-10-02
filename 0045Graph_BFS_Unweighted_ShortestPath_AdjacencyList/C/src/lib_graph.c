#include "lib_graph.h"

void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
		return ;
	}

	(*this).nodeArray = NULL;
	(*this).size = -1;
	
	//Method Functions binding
	(*this).Create = &GRAPH_METHOD_Create;
	(*this).Destroy = &GRAPH_METHOD_Destroy;
	(*this).AddEdge_Directed = &GRAPH_METHOD_AddEdge_Directed;
	(*this).AddEdge = &GRAPH_METHOD_AddEdge;
	(*this).Print = &GRAPH_METHOD_Print;
	(*this).BFS_ShortestPath = &GRAPH_METHOD_BFS_ShortestPath;

	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		DEBUG("ERROR: this is NULL.\n");
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
		DEBUG("ERROR: this is NULL.\n");
		return NULL;
	}
	
	//Exception Handling2
	if (this->nodeArray != NULL){
		DEBUG("ERROR: this->nodeArray is not NULL.\n");
		return NULL;
	}

	(*this).nodeArray = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE)*sizeArg);
	(*this).size = sizeArg;

	for (int i=0; i<sizeArg ; i++){
		this->nodeArray[i].node_id = i;
		this->nodeArray[i].next = NULL;
		this->nodeArray[i].prev = NULL;
	}

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	GRAPH_NODE *tempNode = NULL;
	GRAPH_NODE *tempNextNode = NULL;

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
		tempNode = (*this).nodeArray+i;
		tempNode = tempNode->next;
		while(tempNode != NULL){
			tempNextNode = tempNode->next;
			free(tempNode);
			tempNode = tempNextNode;
		}
	}

	free(this->nodeArray);
	this->nodeArray = NULL;
	this->size = -1;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB)
{
	GRAPH_NODE *node_Array = NULL;
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

	node_Array = this->nodeArray;
	tempNode = node_Array + nodeA;
	while(tempNode->next != NULL){
		tempNode = tempNode->next;
	}
	tempNode->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	tempNode->next->next = NULL;
	tempNode->next->prev = tempNode;
	tempNode->next->node_id = nodeB;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB)
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

	(*this).AddEdge_Directed(this, nodeA, nodeB);
	(*this).AddEdge_Directed(this, nodeB, nodeA);

	return this;
}

GRAPH *GRAPH_METHOD_Print(GRAPH *this)
{
	GRAPH_NODE *node_Array = NULL;
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

	node_Array = this->nodeArray;

	for (int i=0 ; i<(*this).size ; i++){
		printf("[Node]: %d [Edge]: ", node_Array[i].node_id);
		tempNode = node_Array[i].next;
		while(tempNode != NULL){
			printf(" %d", tempNode->node_id);
			tempNode = tempNode->next;
		}
		printf("\n");
	}
	
	return this;
}

int GRAPH_METHOD_BFS_ShortestPath(GRAPH *this, int *pathOutput, int nodeA, int nodeB)
{
	int ret = -1;
	char *visitVector = NULL;
	int *departureVector = NULL;
	QUEUE bfs_Queue;
	QUEUE_CONSTRUCTOR(&bfs_Queue);
	GRAPH_NODE *currentNode = NULL;
	GRAPH_NODE *tempNode = NULL;
	GRAPH_NODE *node_Array = NULL;
	int loopCtl = 0;

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

	//Exception Handling3
	if (pathOutput == NULL){
		DEBUG("ERROR: pathOutput is NULL.\n");
		return -3;
	}

	//Creating bfsQueue
	bfs_Queue.Create(&bfs_Queue, this->size);
	node_Array = this->nodeArray;

	//Creating visitVector and departureVector
	visitVector = (char *)malloc(sizeof(char)*(this->size));
	memset(visitVector, 0, sizeof(char)*(this->size));
	departureVector = (int *)malloc(sizeof(int)*(this->size));
	for (int i=0; i<this->size ; i++){
		departureVector[i] = -1;
	}

	//BFS start
	currentNode = node_Array + nodeA;
	bfs_Queue.Enqueue(&bfs_Queue, currentNode);
	visitVector[currentNode->node_id] = 1;
	departureVector[currentNode->node_id] = -1;

	loopCtl = 1;
	while(loopCtl){
		if (bfs_Queue.Empty(&bfs_Queue)){
			ret = -1;
			break;
		}

		//Visit Check
		bfs_Queue.Dequeue(&bfs_Queue, (void *)(&currentNode));
		currentNode = node_Array + (currentNode->node_id);
		visitVector[currentNode->node_id] = 2;

		tempNode = currentNode->next;
		while(tempNode != NULL){
			if (visitVector[tempNode->node_id] != 0){
				tempNode = tempNode->next;
				continue;
			}

			//When the tempNode is not visited yet.
			bfs_Queue.Enqueue(&bfs_Queue, tempNode);
			visitVector[tempNode->node_id] = 1;
			departureVector[tempNode->node_id] = currentNode->node_id;

			if (tempNode->node_id != nodeB){
				tempNode = tempNode->next;
				continue;
			}

			//Whent the destination is found.(tempNode->node_id == nodeB)
			ret = 0;
			while (1){
				pathOutput[ret] = tempNode->node_id;
				tempNode = node_Array + departureVector[tempNode->node_id];
				ret ++;
				if (tempNode->node_id == nodeA){
					pathOutput[ret] = tempNode->node_id;
					break;
				}
			}
			loopCtl = 0;
			break;
		}
	}

	free(visitVector);
	free(departureVector);
	QUEUE_DESTRUCTOR(&bfs_Queue);
	return ret;
}
