#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.h"

//Type Definitions and Declarations
typedef struct _GRAPH_NODE GRAPH_NODE;
typedef struct _GRAPH GRAPH;

struct _GRAPH_NODE {
	int node_id;
	GRAPH_NODE *prev, *next;
};

struct _GRAPH {
	GRAPH_NODE *nodeArray;
	int size;

	//Methods
	GRAPH *(*CreateGraph)(GRAPH *this, int sizeArg);
	GRAPH *(*DestroyGraph)(GRAPH *this);
	GRAPH *(*AddEdge_Directed)(GRAPH *this, int nodeA, int nodeB);
	GRAPH *(*AddEdge)(GRAPH *this, int nodeA, int nodeB);
	int *(*Create_DFS_Buffer)(GRAPH *this);
	GRAPH *(*Release_DFS_Buffer)(GRAPH *this, int *bufferArg);
	GRAPH *(*DFS)(GRAPH *this, int *bufferArg);
	GRAPH *(*Print)(GRAPH *this);

};

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *);
void GRAPH_DESTRUCTOR(GRAPH *);
GRAPH *GRAPH_METHOD_CreateGraph(GRAPH *this, int sizeArg);
GRAPH *GRAPH_METHOD_DestroyGraph(GRAPH *this);
GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB);
GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB);
int *GRAPH_METHOD_Create_DFS_Buffer(GRAPH *this);
GRAPH *GRAPH_METHOD_Release_DFS_Buffer(GRAPH *this, int *bufferArg);
GRAPH *GRAPH_METHOD_DFS(GRAPH *this, int *bufferArg);
GRAPH *GRAPH_METHOD_Print(GRAPH *this);
int DFS_SubFunc_Recursive(GRAPH *, int, char *, int *);

#endif
