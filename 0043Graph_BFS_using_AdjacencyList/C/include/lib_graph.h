#ifndef __GRAPH_HEADER__
#define __GRAPH_HEADER__

#include "common.h"
#include "lib_queue.h"

//Type definitions and declarations
typedef struct _GRAPH_NODE GRAPH_NODE;
typedef struct _GRAPH GRAPH;

struct _GRAPH_NODE {
	int node_id;
	GRAPH_NODE *prev;
	GRAPH_NODE *next;
};

struct _GRAPH {
	GRAPH_NODE *nodeArray;
	int size;

	//Methods
	GRAPH *(*CreateGraph)(GRAPH* this, int);
	GRAPH *(*DestroyGraph)(GRAPH *this);
	GRAPH *(*AddEdge_Directed)(GRAPH *this, int, int);
	GRAPH *(*AddEdge)(GRAPH *this, int, int);
	int *(*Create_BFS_Buffer)(GRAPH *this);
	int (*Release_BFS_Buffer)(GRAPH *this, int *);
	GRAPH *(*BFS)(GRAPH *this, int *);
};

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *this);
void GRAPH_DESTRUCTOR(GRAPH *this);
GRAPH *GRAPH_METHOD_CreateGraph(GRAPH *this, int sizeArg);
GRAPH *GRAPH_METHOD_DestroyGraph(GRAPH *this);
GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB);
GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB);
int *GRAPH_METHOD_Create_BFS_Buffer(GRAPH *this);
int GRAPH_METHOD_Release_BFS_Buffer(GRAPH *this, int *);
GRAPH *GRAPH_METHOD_BFS(GRAPH *this, int *resultStore);
#endif
