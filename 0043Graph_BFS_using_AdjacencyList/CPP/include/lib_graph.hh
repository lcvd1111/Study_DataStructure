#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type Definitions and Declaraitions
typedef class _GRAPH GRAPH;
class _GRAPH {
public:
	std::vector<int> *nodeArray;
	int size;

	//Methods
	_GRAPH(void);
	~_GRAPH(void);
	GRAPH *CreateGraph(int sizeArg);
	GRAPH *DestroyGraph(void);
	GRAPH *AddEdge_Directed(int nodeA, int nodeB);
	GRAPH *AddEdge(int nodeA, int nodeB);
	GRAPH *BFS(std::vector<int> &BFSresult);
	GRAPH *Print(void);
};

#endif
