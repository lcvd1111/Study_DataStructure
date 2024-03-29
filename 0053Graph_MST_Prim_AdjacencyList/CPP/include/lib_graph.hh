#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type Definitions and Declarations
typedef class _GRAPH_NODE GRAPH_NODE;
typedef GRAPH_NODE NODE;
typedef class _GRAPH GRAPH;
typedef struct _CUMSTOM_COMPARE CUSTOM_COMPARE;
typedef class _HEAP_NODE HEAP_NODE;

class _GRAPH_NODE {
public:
	int node_id;
	int weight;
};

class _GRAPH {
public:
	std::vector<NODE> *nodeArray;
	int size;

	//Method Declarations
	_GRAPH(void);
	~_GRAPH(void);
	GRAPH *Create(int);
	GRAPH *Destroy(void);
	GRAPH *AddEdge_Directed(int, int, int);
	GRAPH *AddEdge(int, int, int);
	GRAPH *Print(void);
	GRAPH Prim(void);
	int Weight(void); //Caution: It can be used only for Undirected Graph!
};

class _HEAP_NODE:public _GRAPH_NODE {
public:
	int parent_node_id;
};

struct _CUMSTOM_COMPARE {
public:
	bool operator()(HEAP_NODE argX, HEAP_NODE argY);	
};
#endif
