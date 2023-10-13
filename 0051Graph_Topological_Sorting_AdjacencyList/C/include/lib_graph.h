#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.h"
#include "lib_queue.h"

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
	GRAPH *(*Create)(GRAPH *, int);
	GRAPH *(*Destroy)(GRAPH *);
	GRAPH *(*AddEdge_Directed)(GRAPH *, int, int);
	GRAPH *(*AddEdge)(GRAPH *, int, int);
	GRAPH *(*Print)(GRAPH *);
	GRAPH *(*TopologicalSort)(GRAPH *, int*);
};

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *this);
void GRAPH_DESTRUCTOR(GRAPH *this);
GRAPH *GRAPH_METHOD_Create(GRAPH *, int);
GRAPH *GRAPH_METHOD_Destroy(GRAPH *);
GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *, int, int);
GRAPH *GRAPH_METHOD_AddEdge(GRAPH *, int, int);
GRAPH *GRAPH_METHOD_Print(GRAPH *);
GRAPH *GRAPH_METHOD_TopologicalSort(GRAPH *, int *);

#endif
