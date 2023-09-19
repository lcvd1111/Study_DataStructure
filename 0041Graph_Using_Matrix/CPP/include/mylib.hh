#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <iostream>

#define DEBUG std::cout<<"["<<__func__<<","<<__LINE__<<"]"

//Type Definitions and Declarations
typedef class _GRAPH GRAPH;

class _GRAPH {
public:
	char **matrix;
	int size;

	//Methods
	_GRAPH(void);
	_GRAPH(int);
	~_GRAPH(void);
	GRAPH *AddVertex(int, int);
	GRAPH *DeleteVertex(int, int);
	GRAPH *Print(void);
};


#endif
