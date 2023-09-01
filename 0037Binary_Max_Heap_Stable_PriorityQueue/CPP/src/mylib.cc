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
	heapArray[lastIndex].id = idArg;
	strncpy(heapArray[lastIndex].data, dataArg, STRING_LEN);
	heapArray[lastIndex].enqOrder = lastEnqOrder;
	this->lastEnqOrder += 1;

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

HEAP *HEAP::Dequeue_P(HEAP_NODE *outputStore)
{
	long int currentIndex = 0;

	//Exception Handling
	if (this == NULL){
		STD_COUT << "ERROR: Object itself is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (this->heapArray == NULL){
		STD_COUT << "ERROR: Member variable heapArray is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling3
	if (outputStore == NULL){
		STD_COUT << "ERROR: outputStore is NULL." << std::endl;
		return NULL;
	}

	//When the queue is Empty
	if (this->lastIndex == -1){
		this->lastEnqOrder = 0;
		return NULL;
	}

	//Feeling the outputStorage with root node's data
	outputStore->id = heapArray[0].id;
	strncpy(outputStore->data, heapArray[0].data, STRING_LEN);
	outputStore->enqOrder = heapArray[0].enqOrder;

	//When the queue becomes empty after the dequeueing
	if (this->lastIndex == 0){
		this->lastIndex = -1;
		this->lastEnqOrder = 0;
		return this;
	}

	//Copying the last nodes data to root node.
	heapArray[0].id = heapArray[lastIndex].id;
	strncpy(heapArray[0].data, heapArray[lastIndex].data, STRING_LEN);
	heapArray[0].enqOrder = heapArray[lastIndex].enqOrder;
	this->lastIndex -= 1;

	//Iterative Swapping
	//The variable current Index is 0 currently.
	while(1){
		//If the current node has no children at all
		if (currentIndex*2+1 > lastIndex)
			return this;

		//If the current node has only a child.(left Child)
		if (currentIndex*2+1 == lastIndex){
			if (heapArray[currentIndex*2+1].id > heapArray[currentIndex].id
				||
				(heapArray[currentIndex*2+1].id == heapArray[currentIndex].id 
				 && heapArray[currentIndex*2+1].enqOrder < heapArray[currentIndex].enqOrder)){
				SwapNode(heapArray+currentIndex, heapArray+currentIndex*2+1);
				currentIndex = 2*currentIndex + 1;
				return this;//Iteration is not needed anymore bc left child is a leaf node.
			}
			return this;
		}

		//If the current node has both left and right children.
		////Exception Handling
		if (!(currentIndex*2+1 < lastIndex)){
			STD_COUT << "ERROR: Unexpected Situation occured." << std::endl;
			return NULL;
		}

		////When the swap is not needed
		if (heapArray[currentIndex].id > heapArray[currentIndex*2+1].id
			&& heapArray[currentIndex].id > heapArray[currentIndex*2+2].id)
			return this;

		////When there exists at least one child whose id is bigger or equal to current node.
		if (heapArray[currentIndex*2+1].id > heapArray[currentIndex*2+2].id){
			if (heapArray[currentIndex].id == heapArray[currentIndex*2+1].id
				&& heapArray[currentIndex].enqOrder < heapArray[currentIndex*2+1].enqOrder){
				return this;
			}
			SwapNode(heapArray+currentIndex, heapArray+currentIndex*2+1);
			currentIndex = currentIndex*2+1;
			continue;
		}

		if (heapArray[currentIndex*2+1].id < heapArray[currentIndex*2+2].id){
			if (heapArray[currentIndex].id == heapArray[currentIndex*2+2].id
				&& heapArray[currentIndex].enqOrder < heapArray[currentIndex*2+2].enqOrder){
				return this;
			}
			SwapNode(heapArray+currentIndex, heapArray+currentIndex*2+2);
			currentIndex = currentIndex*2+2;
			continue;
		}
		
		////When both children have same id value to each other
		if (!(heapArray[currentIndex*2+1].id == heapArray[currentIndex*2+2].id)){
			STD_COUT << "ERROR: Unexpeted Situation occured." << std::endl;
			return NULL;
		}

		if (heapArray[currentIndex*2+1].enqOrder < heapArray[currentIndex*2+2].enqOrder){
			if (heapArray[currentIndex].id == heapArray[currentIndex*2+1].id
				&& heapArray[currentIndex].enqOrder < heapArray[currentIndex*2+1].enqOrder){
				return this;
			}
			SwapNode(heapArray+currentIndex, heapArray+currentIndex*2+1);
			currentIndex = currentIndex*2+1;
			continue;
		}

		if (heapArray[currentIndex*2+1].enqOrder > heapArray[currentIndex*2+2].enqOrder){
			if (heapArray[currentIndex].id == heapArray[currentIndex*2+2].id
				&& heapArray[currentIndex].enqOrder < heapArray[currentIndex*2+2].enqOrder){
				return this;
			}
			SwapNode(heapArray+currentIndex, heapArray+currentIndex*2+2);
			currentIndex = currentIndex*2+2;
			continue;
		}

		//Exception Handling
		STD_COUT << "ERROR: Unexpected situation occured." << std::endl;
	}

	return this;
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
