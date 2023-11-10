#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.h"

//Type Definitions and Declarations
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
	GRAPH *(*AddEdge_Directed)(GRAPH *, int, int, int weight);
	GRAPH *(*AddEdge)(GRAPH *, int, int, int weight);
	void (*Print)(GRAPH *);
	GRAPH *(*Kruskal)(GRAPH *, GRAPH *);
};

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *);
void GRAPH_DESTRUCTOR(GRAPH *);
GRAPH *GRAPH_METHOD_Create(GRAPH *, int);
GRAPH *GRAPH_METHOD_Destroy(GRAPH *);
GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *, int, int, int weight);
GRAPH *GRAPH_METHOD_AddEdge(GRAPH *, int, int, int weight);
void GRAPH_METHOD_Print(GRAPH *);
GRAPH *GRAPH_METHOD_Kruskal(GRAPH *, GRAPH *);

#endif
