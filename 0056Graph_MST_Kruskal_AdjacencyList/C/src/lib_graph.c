#include "lib_graph.h"

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

	return this;
}

GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB, int weight)
{
	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB, int weight)
{
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
			printf("(%d, %d) ", tmpNode->node_id, tmpNode->weight);
			tmpNode = tmpNode->next;
		}
		printf(COLOR_BLACK "\n");
	}

	return ;
}

GRAPH *GRAPH_METHOD_Kruskal(GRAPH *this, GRAPH *outputStore)
{
	return this;
}
