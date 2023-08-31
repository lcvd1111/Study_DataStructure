#include "mylib.hh"

//Function and Methods Definitions
HEAP::STABLE_MAX_HEAP(void)
{
	this->heapArray = NULL;
	return ;
}

HEAP::STABLE_MAX_HEAP(int levelArg)
{
	if (levelArg < 1){
		STD_COUT << "ERROR: levelArg is smaller than 1." << std::endl;
		this->heapArray = NULL;//Preventing the error that can happen in destructor.
		return;
	}
	this->level = levelArg;
	this->size = 1;
	for (int i=0 ; i<levelArg ; i++)
		this->size = 2*(this->size);

	this->size -= 1;
	this->lastIndex = -1;
	this->lastEnqOrder = 0;
	
	this->heapArray = new HEAP_NODE[this->size];

	if (heapArray == NULL){
		STD_COUT << "ERROR: memory alloc failed." << std::endl;
		return;
	}

	return ;
}

HEAP::~STABLE_MAX_HEAP(void){
	if (this->heapArray == NULL)
		return ;

	else
		free(this->heapArray);

	return ;
}

HEAP *HEAP::Enqueue(int idArg, const char *dataArg)
{
	long int currentIndex = 0;

	//Exception Handling1
	if (this == NULL){
		STD_COUT << "Object itselft is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (this->heapArray == NULL){
		STD_COUT << "heapArray is NULL." << std::endl;
		return NULL;
	}

	//When the heap is full currently.
	if (this->lastIndex == this->size - 1)
		return NULL;

	//Filling the last node with input data.
	this->lastIndex += 1;
	this->lastEnqOrder += 1;
	heapArray[lastIndex].id = idArg;
	strncpy(heapArray[lastIndex].data, dataArg, STRING_LEN);
	heapArray[lastIndex].enqOrder = lastEnqOrder;

	//When the heap becomes non-empty from being empty after the enqueueing.
	if (lastIndex == 0){
		return this;
	}

	//Iterative Swapping to place last node in to proper position.
	currentIndex = lastIndex;

	while(1){
		//When the current node is a root.
		if (currentIndex == 0){
			return this;
		}

		if (heapArray[currentIndex].id < heapArray[(currentIndex-1)/2].id){
			return this;
		}

		if (heapArray[currentIndex].id == heapArray[(currentIndex-1)/2].id
			&& heapArray[currentIndex].enqOrder > heapArray[(currentIndex-1)/2].enqOrder){
			return this;
		}

		//When the Swapping is needed.
		if (SwapNode(heapArray+currentIndex, heapArray+(currentIndex-1)/2)){
			STD_COUT << "ERROR: SwapNode() failed." << std::endl;
			return NULL;
		}
		currentIndex = (currentIndex-1)/2;
	}

	STD_COUT << "ERROR: Unexpected situation occured." << std::endl;
	return this;
}

HEAP *HEAP::Dequeu_P(HEAP_NODE *outputStore)
{
	return NULL;
}

int SwapNode(HEAP_NODE *nodeA, HEAP_NODE *nodeB)
{
	char stringBuffer[STRING_LEN] = {0,};

	//Exception Handling
	if (nodeA==NULL){
		STD_COUT << "ERROR: node A is NULL." << std::endl;
		return -1;
	}

	if (nodeB==NULL){
		STD_COUT << "ERROR: node B is NULL." << std::endl;
		return -2;
	}

	//id swapping using XOR
	nodeA->id = (nodeA->id) ^ (nodeB->id);
	nodeB->id = (nodeA->id) ^ (nodeB->id);
	nodeA->id = (nodeA->id) ^ (nodeB->id);

	//data swapping
	strncpy(stringBuffer, nodeA->data, STRING_LEN);
	strncpy(nodeA->data, nodeB->data, STRING_LEN);
	strncpy(nodeB->data, stringBuffer, STRING_LEN);

	//enqueued order swapping using XOR
	nodeA->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);
	nodeB->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);
	nodeA->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);
	return 0;
}
