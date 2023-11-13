#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.h"
#include "lib_heap.h"

//Type Defintions and Declarations
typedef struct _GRAPH_NODE GRAPH_NODE;
typedef struct _GRAPH GRAPH;

struct _GRAPH_NODE {
	int node_id;
	int weight;
	GRAPH_NODE *prev, *next;
};

struct _GRAPH {
	GRAPH_NODE *nodeVector;
	int size;

	//Method Functions
	GRAPH *(*Create)(GRAPH *, int);
	GRAPH *(*Destroy)(GRAPH *);
	GRAPH *(*AddEdge_Directed)(GRAPH *, int, int, int);
	GRAPH *(*AddEdge)(GRAPH *, int, int, int);
	GRAPH *(*Print)(GRAPH *);
	GRAPH *(*Dijkstra)(GRAPH *);
};

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *);
void GRAPH_DESTRUCTOR(GRAPH *);
GRAPH *GRAPH_METHOD_Create(GRAPH *, int);
GRAPH *GRAPH_METHOD_Destroy(GRAPH *);
GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *, int, int, int);
GRAPH *GRAPH_METHOD_AddEdge(GRAPH *, int, int, int);
GRAPH *GRAPH_METHOD_Print(GRAPH *);
GRAPH *GRAPH_METHOD_Dijkstra(GRAPH *);

#endif
