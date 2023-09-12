#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_LEN 64
#define DEBUG( x , ... ) printf("[%s %d]" x, __func__, __LINE__, ##__VA_ARGS__)

//Type Defintions and Declarations including the Methods
typedef struct _GRAPH_NODE GRAPH_NODE;
typedef GRAPH_NODE NODE;
typedef struct _GRAPH GRAPH;

struct _GRAPH_NODE {
	char name[STRING_LEN];
	NODE *next;
	NODE *prev;
};

struct _GRAPH {
	NODE **vertexList;
	long int maxSize;
	long int currentSize;
	//Deleting Vertex and Edge is not implemented. Therefore, there is no need to make and exploit the 'currentLastIndex' info.

	//Methods
	long int (*GetIndex)(GRAPH *self, char *);
	GRAPH *(*AddVertex)(GRAPH *self, char *);
	GRAPH *(*AddEdge)(GRAPH *self, long int, long int);
};

//Function Declarations
GRAPH Constructor_Graph(GRAPH *self, long int sizeArg);
int Destructor_Graph(GRAPH *self);
long int Method_GetIndex(GRAPH *self, char *nameArg);
GRAPH *Method_AddVertex(GRAPH *self, char *nameArg);
GRAPH *Method_AddEdge(GRAPH *self, long int indexA, long int indexB);

#endif
