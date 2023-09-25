#include "lib_graph.h"

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *this)
{
	return ;
}

void GRAPH_DESTRUCTOR(GRAPH *this)
{
	return ;
}

GRAPH *GRAPH_METHOD_CretaeGraph(GRAPH *this, int sizeArg)
{
	return this;
}

GRAPH *GRAPH_METHOD_DestroyGraph(GRAPH *this)
{
	return this;
}

GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB)
{
	return this;
}

int *GRAPH_METHOD_Create_BFS_Buffer(GRAPH *this)
{
	int *ret = NULL;

	//Exception Handling1.
	if (this == NULL){
		DEBUG("ERROR: 'this' is NULL.\n");
		return NULL;
	}

	//Exception Handling2.
	if (this->nodeArray == NULL){
		DEBUG("RROR: 'this->nodeArray' is NULL.\n");
		return NULL;
	}

	ret = (int *)malloc(sizeof(int)*(this->size));
	for (int i=0; i<(this->size) ; i++){
		ret[i] = -1;
	}
	
	return ret;
}

GRAPH *GRAPH_METHOD_BFS(GRAPH *this, int *resultStore)
{
	return this;
}

