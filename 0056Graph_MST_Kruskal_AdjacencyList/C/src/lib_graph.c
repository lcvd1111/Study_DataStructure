#include "lib_graph.h"
#include "lib_heap.h"
#include "lib_unionfind.h"

//Function Definitions
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("The first argument(='this') is NULL.\n");
		return;
	}

	this->nodeVector = NULL;
	this->size = 0;

	//Binding Method functions
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
		PRINTF_ERROR("The first argument(='this') is NULL.\n");
		return ;
	}

	if (this->nodeVector != NULL){
		(*this).Destroy(this);
		return ;
	}

	return ;
}

GRAPH *GRAPH_METHOD_Create(GRAPH *this, int sizeArg)
{
	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("the first argument(='this') is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->nodeVector != NULL){
		PRINTF_ERROR("this->nodeVector is not NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (sizeArg < 1){
		PRINTF_ERROR("sizeArg is smaller than 1.\n");
		return NULL;
	}

	this->size = sizeArg;
	this->nodeVector = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE)*(sizeArg));
	for (int i=0 ; i<(this->size) ; i++){
		(this->nodeVector)[i].node_id = i;
		(this->nodeVector)[i].weight = 0;
		(this->nodeVector)[i].prev = NULL;
		(this->nodeVector)[i].next = NULL;
	}

	return this;
}

GRAPH *GRAPH_METHOD_Destroy(GRAPH *this)
{
	GRAPH_NODE *tmp=NULL, *tmp_next=NULL;
	GRAPH_NODE *pNodeVector = NULL;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("the first argument(='this') is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->nodeVector == NULL){
		PRINTF_ERROR("this->nodeVector is NULL.\n");
		return NULL;
	}

	pNodeVector = this->nodeVector;

	for (int i=0 ; i<(this->size) ; i++){
		tmp = pNodeVector + i;
		if (tmp->next == NULL){
			continue;
		}
		tmp = tmp->next;
		while(tmp != NULL){
			tmp_next = tmp->next;
			free(tmp);
			tmp = tmp_next;
		}
	}

	this->nodeVector = NULL;
	this->size = 0;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB, int weightArg)
{
	GRAPH_NODE *tmp = NULL;

	//Exception Handling
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (this->nodeVector == NULL){
		PRINTF_ERROR("ERROR: this->nodeArray is NULL.\n");
		return NULL;
	}

	//Exception Handling
	if (nodeA >= this->size){
		PRINTF_ERROR("ERROR: nodeA >= size\n");
		return NULL;
	}

	//Exception Handling
	if (nodeB >= this->size){
		PRINTF_ERROR("ERROR: nodeB >= size\n");
		return NULL;
	}

	tmp = (this->nodeVector) + nodeA;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}

	tmp->next = (GRAPH_NODE *)malloc(sizeof(GRAPH_NODE));
	tmp->next->prev = tmp;
	tmp->next->next = NULL;
	tmp->next->node_id = nodeB;
	tmp->next->weight = weightArg;

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB, int weight)
{
	(*this).AddEdge_Directed(this, nodeA, nodeB, weight);
	(*this).AddEdge_Directed(this, nodeB, nodeA, weight);
	return this;
}

void GRAPH_METHOD_Print(GRAPH *this)
{
	GRAPH_NODE *pNodeVector = NULL;
	GRAPH_NODE *tmpNode = NULL;

	//Exception Handling
	if (this==NULL){
		return ;
	}

	//Exception Handling
	if (this->nodeVector == NULL){
		return ;
	}

	pNodeVector = this->nodeVector;

	for (int i=0 ; i<(this->size) ; i++){
		printf("[Node]: " COLOR_BLUE "%d" COLOR_BLACK " [Neighbor]: ", pNodeVector[i].node_id);
		tmpNode = pNodeVector[i].next;
		while(tmpNode != NULL){
			printf(COLOR_BLUE "(%d,%d) ", tmpNode->node_id, tmpNode->weight);
			tmpNode = tmpNode->next;
		}
		printf(COLOR_BLACK "\n");
	}

	return ;
}

GRAPH *GRAPH_METHOD_Kruskal(GRAPH *this, GRAPH *outputStore)
{
	GRAPH_NODE *currentNode=NULL, *tmpNode=NULL;
	GRAPH_NODE *pNodeVector = NULL;
	HEAP kruskalPQ;
	HEAP_CONSTRUCTOR(&kruskalPQ);
	UNION_FIND kruskalUF;
	UNION_FIND_CONSTRUCTOR(&kruskalUF);
	HEAP_NODE heapNode;

	//Exception Handling.
	if (this == NULL){
		PRINTF_ERROR("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling.
	if (this->nodeVector == NULL){
		PRINTF_ERROR("ERROR: 'this->nodeVector' is NULL.\n");
		return NULL;
	}
	
	//Exception Handling.
	if (outputStore == NULL){
		PRINTF_ERROR("ERROR: 'outputStore' is NULL.\n");
		return NULL;
	}

	//Initializing the auxiliary objects.
	pNodeVector = this->nodeVector;
	kruskalPQ.Create(&kruskalPQ, 10);
	kruskalUF.Create(&kruskalUF, this->size);
	if (outputStore->nodeVector != NULL){
		(*outputStore).Destroy(outputStore);
	}
	(*outputStore).Create(outputStore, this->size);

	//Enqueueing every edge to priority queue.
	for (int i=0 ; i<this->size ; i++){
		currentNode = pNodeVector + i;
		tmpNode = currentNode->next;
		while(tmpNode != NULL){
			if (tmpNode->node_id < currentNode->node_id){
				tmpNode = tmpNode->next;
				continue;
			}
			heapNode.key = tmpNode->weight;
			heapNode.nodeA = currentNode->node_id;
			heapNode.nodeB = tmpNode->node_id;
			kruskalPQ.Enqueue(&kruskalPQ, &heapNode);

			tmpNode = tmpNode->next;
		}
	}

	//Dequeueing
	while(kruskalPQ.lastIndex != -1){
		kruskalPQ.Peek(&kruskalPQ, &heapNode);
		kruskalPQ.Dequeue(&kruskalPQ);

		//Checking whether they are already connected or not using UnionFind
		if (kruskalUF.Unite(&kruskalUF, heapNode.nodeA, heapNode.nodeB) != NULL){
			(*outputStore).AddEdge(outputStore, heapNode.nodeA, heapNode.nodeB, heapNode.key);
		}
	}

	//Destroying the auxiliary objects.
	kruskalPQ.Destroy(&kruskalPQ);
	kruskalUF.Destroy(&kruskalUF);

	HEAP_DESTRUCTOR(&kruskalPQ);
	UNION_FIND_DESTRUCTOR(&kruskalUF);
	return this;
}
