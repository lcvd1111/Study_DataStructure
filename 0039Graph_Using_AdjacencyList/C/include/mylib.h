#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 64
#define DEBUG(x, ... ) printf("[%d %s]" x, __LINE__, __func__, ##__VA_ARGS__)

//Type Declarations and Definitions include Methods Declarations.
typedef struct _GRAPH_NODE GRAPH_NODE;
typedef struct _GRAPH GRAPH;

struct _GRAPH_NODE {
	char data[STRING_LEN];
	GRAPH_NODE *next;
	GRAPH_NODE *prev;
};

struct _GRAPH {
	long int maxSize;
	long int currentSize;
	long int currentLastIndex;
	GRAPH_NODE **vertexList;

	//Methods Declarations
	long int (*ReturnIndex)(GRAPH *self, char *dataArg);
	int (*ReturnDegree)(GRAPH *self, long int indexArg);
	GRAPH *(*AddVertex)(GRAPH *self, char *data);
	GRAPH *(*AddEdge)(GRAPH *self, long int originIndex, long int destIndex);//Because it is an undirected graph, there iis no difference between the originIndex and destIndex
	GRAPH *(*DeleteVertex)(GRAPH *self, char *data);
	GRAPH *(*DeleteEdge)(GRAPH *self, long int originIndex, long int destIndex);
};

//Function Declarations
GRAPH Constructor_Graph(GRAPH *self, long int maximumSize);
int Destructor_Graph(GRAPH *self);

long int Method_ReturnIndex(GRAPH *self, char *dataArg);
int Method_ReturnDegree(GRAPH *self, long int indexArg);
GRAPH *Method_AddVertex(GRAPH *self, char *data);
GRAPH *Method_AddEdge(GRAPH *self, long int originIndex, long int destIndex);
GRAPH *Method_DeleteVertex(GRAPH *self, char *data); 
GRAPH *Method_DeleteEdge(GRAPH *self, long int originIndex, long int destIndex);

#endif
