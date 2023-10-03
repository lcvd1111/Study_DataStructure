#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.h"
#include "lib_queue.h"

//Type Definition and Declaration
typedef struct _GRAPH GRAPH;

struct _GRAPH {
	int **matrix;
	int size;

	//Methods
	GRAPH *(*Create)(GRAPH *, int);
	GRAPH *(*Destroy)(GRAPH *);
	GRAPH *(*AddEdge_Directed)(GRAPH *, int, int);
	GRAPH *(*AddEdge)(GRAPH *, int, int);
	GRAPH *(*Print)(GRAPH *);
	int (*BFS_ShortestPath)(GRAPH *, int *, int, int);
};


//Function Declarations
void GRAPH_CONSTRUCTOR(GRAPH *);
void GRAPH_DESTRUCTOR(GRAPH *);
GRAPH *GRAPH_METHOD_Create(GRAPH *, int);
GRAPH *GRAPH_METHOD_Destroy(GRAPH *);
GRAPH *GRAPH_METHOD_AddEdge_Directed(GRAPH *, int, int);
GRAPH *GRAPH_METHOD_AddEdge(GRAPH *, int, int);
GRAPH *GRAPH_METHOD_Print(GRAPH *);
int GRAPH_METHOD_BFS_ShortestPath(GRAPH *, int *, int, int);
int CalcPath(int, int, int *, int *);
#endif
