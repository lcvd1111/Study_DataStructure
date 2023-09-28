#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.h"
#include "lib_queue.h"

//Type Definitions and Delcarations
typedef struct _GRAPH GRAPH;

struct _GRAPH {
	char **matrix;
	int size;

	//Methods Delcarations
	GRAPH *(*CreateGraph)(GRAPH *this, int sizeArg);
	GRAPH *(*DestroyGraph)(GRAPH *this);
	GRAPH *(*AddEdge_Directed)(GRAPH *this, int, int);
	GRAPH *(*AddEdge)(GRAPH *this, int, int);
	int *(*Create_BFS_Buffer)(GRAPH *this);
	int (*Release_BFS_Buffer)(GRAPH *this, int *bufferArg);
	GRAPH *(*BFS)(GRAPH *this, int *bufferArg);
	GRAPH *(*Print)(GRAPH *this);
};

//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *);
void GRAPH_DESTRUCTOR(GRAPH *);
GRAPH *GRAPH_METHOD_CreateGraph(GRAPH *this, int sizeArg);
GRAPH *GRAPH_METHOD_DestroyGraph(GRAPH *this);
GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *this, int nodeA, int nodeB);
GRAPH *GRAPH_METHOD_AddEdge(GRAPH *this, int nodeA, int nodeB);
int *GRAPH_METHOD_Create_BFS_Buffer(GRAPH *this);
int GRAPH_METHOD_Release_BFS_Buffer(GRAPH *this, int *);
GRAPH *GRAPH_METHOD_BFS(GRAPH *this, int *resultStore);
GRAPH *GRAPH_METHOD_Print(GRAPH *this);

#endif
