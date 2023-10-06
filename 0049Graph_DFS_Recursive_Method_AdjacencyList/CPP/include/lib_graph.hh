#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type Definitions and Declarations
typedef class _GRAPH GRAPH;

class _GRAPH {
public:
	std::vector<int> *nodeArray;
	int size;

	//Methods
	_GRAPH(void);
	~_GRAPH(void);
	GRAPH *Create(int sizeArg);
	GRAPH *Destroy(void);
	GRAPH *AddEdge_Directed(int, int);
	GRAPH *AddEdge(int, int);
	GRAPH *DFS(std::vector<int> &outputStorage);
	GRAPH *Print(void);
private:
	int RecursiveDFS
		(int nextNode, std::vector<char> &visitVector, std::vector<int> &outputStore);
};


#endif
