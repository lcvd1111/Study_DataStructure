#ifndef __LIB_GRAPH_HEADER__
#define __LIB_GRAPH_HEADER__

#include "common.hh"

//Type Definitions and Declarations
typedef class _GRAPH GRAPH;
typedef class _HEAP_NODE HEAP_NODE;
typedef class _HEAP_COMPARATOR HEAP_COMPARATOR;

class _GRAPH {
public:
	int **matrix;
	int size;

	//Method Functions
	_GRAPH(void);
	~_GRAPH(void);
	GRAPH *Create(int);
	GRAPH *Destroy(void);
	GRAPH *AddEdge_Directed(int, int, int);
	GRAPH *AddEdge(int, int, int);
	GRAPH *Print(void);
	int Weight(void);
	int Dijkstra(int);
};

//Below things are used for priority queue for kruskal algorithm
class _HEAP_NODE {
public:
	int node_id;
	int parent_node_id;
	int distance_from_departure;
};

class _HEAP_COMPARATOR {
public:
	bool operator()(HEAP_NODE &, HEAP_NODE &);
};
#endif
