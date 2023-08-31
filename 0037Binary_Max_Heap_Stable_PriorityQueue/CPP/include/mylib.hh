#ifndef __MYLIB_HEADER__
#define __MYLIB_HEADER__

#include <iostream>
#include <cstring>
#include <cstdlib>

#define STD_COUT std::cout<<"["<<__LINE__<<" "<<__func__<<"]"
#define STRING_LEN 32

//Type declarations and definitions, Method Declarations
typedef class STABLE_MAX_HEAP_NODE HEAP_NODE;
class STABLE_MAX_HEAP_NODE {
public:
	unsigned int id;
	char data[STRING_LEN];
	unsigned int enqOrder;
};

typedef class STABLE_MAX_HEAP HEAP;
class STABLE_MAX_HEAP{
public:
	HEAP_NODE *heapArray;
	int level;
	unsigned int size;
	long int lastIndex;
	long int lastEnqOrder;
	
	//Methods Declarations
	STABLE_MAX_HEAP(void);
	STABLE_MAX_HEAP(int levelArg);
	~STABLE_MAX_HEAP(void);
	HEAP *Enqueue(int, const char *);
	HEAP *Dequeu_P(HEAP_NODE *); //Dequeue_P = Dequeueing with Priority
};

//Function Declarations
int SwapNode(HEAP_NODE *, HEAP_NODE *);
#endif
