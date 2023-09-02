#include "mylib.hh"

//Methods Function Definitions
HEAP::_STABLE_MIN_HEAP(void)
{
	this->heapArray = NULL;
	this->level = -1;
	this->size = -1;
	this->lastIndex = -1;
	this->lastEnqOrder = -1;
	
	return ;
}

HEAP::_STABLE_MIN_HEAP(int levelArg)
{
	this->level = levelArg;
	this->size = 1;
	
	for (int i=0 ; i<levelArg; i++){
		this->size = (this->size)*2;
	}
	this->size -= 1;

	this->lastIndex = -1;
	this->lastEnqOrder = 0;
	this->heapArray = new HEAP_NODE[this->size];
	
	memset(this->heapArray, 0, sizeof(HEAP_NODE)*(this->size));

	return ;
}

HEAP::~_STABLE_MIN_HEAP(void)
{
	if (this->heapArray == NULL){
		return ;
	}

	delete[] this->heapArray;
	return ;
}

HEAP *HEAP::Enqueue(int idArg, const char *dataArg)
{
	long int currentIndex = 0;
	//Exception Handling
	if (this->heapArray == NULL){
		DEBUG << "ERROR: this->heapArray is NULL." << std::endl;
		return NULL;
	}

	//When the heap is full currently.
	if (this->lastIndex + 1 == this->size){
		return NULL;
	}

	//Filling the last node with the inputted data.
	this->lastIndex += 1;
	(this->heapArray)[this->lastIndex].id = idArg;
	strncpy((this->heapArray)[this->lastIndex].data, dataArg, STRING_LEN);
	(this->heapArray)[this->lastIndex].enqOrder = this->lastEnqOrder;
	this->lastEnqOrder += 1;
	
	//When the heap was empty before the enqueueing
	if (this->lastIndex == 0){
		return this;
	}

	//Iterative Swapping.
	currentIndex = this->lastIndex;

	while(1){
		//When the current node is a root node.
		if (currentIndex == 0){
			return this;
		}

		if (heapArray[currentIndex].id < heapArray[(currentIndex-1)/2].id){
			SwapNode(heapArray+currentIndex, heapArray+(currentIndex-1)/2);
			currentIndex = (currentIndex-1)/2;
			continue;
		}

		if (heapArray[currentIndex].id == heapArray[(currentIndex-1)/2].id
			&& heapArray[currentIndex].enqOrder < heapArray[(currentIndex-1)/2].enqOrder){
			SwapNode(heapArray+currentIndex, heapArray+(currentIndex-1)/2);
			currentIndex = (currentIndex-1)/2;
			continue;
		}

		return this;
	}

	//Exception Handling
	DEBUG << "ERROR: Unexpected Situation Occured." << std::endl;
	return NULL;
}

HEAP *HEAP::Dequeue(HEAP_NODE *outputStore)
{
	long int currentIndex = 0;

	//Exception Handling
	if (this->heapArray == NULL){
		DEBUG << "ERROR: this->heapArray is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling
	if (outputStore == NULL){
		DEBUG << "ERROR: outputStore is NULL." << std::endl;
		return NULL;
	}

	//When the heap is empty.
	if (this->lastIndex == -1){
		this->lastEnqOrder = 0;
		return NULL;
	}

	//Filling the outputStore with the root node's data
	outputStore->id = heapArray[0].id;
	strncpy(outputStore->data, heapArray[0].data, STRING_LEN);
	outputStore->enqOrder = heapArray[0].enqOrder;

	//When the heap becomes empty after the dequeueing.
	if (this->lastEnqOrder == 0){
		this->lastEnqOrder = -1;
		return this;
	}

	//Copying the last node's data to root node.
	heapArray[0].id = heapArray[this->lastIndex].id;
	strncpy(heapArray[0].data, heapArray[this->lastIndex].data, STRING_LEN);
	heapArray[0].enqOrder = heapArray[this->lastIndex].enqOrder;
	this->lastIndex -= 1;

	//Iterative Swapping
	while(1){
		//When the current node has no children at all.
		if (currentIndex*2+1 > this->lastIndex){
			return this;
		}

		//When the current node has only a left child.
		if (currentIndex*2+1 == this->lastIndex){
			if (heapArray[currentIndex].id < heapArray[currentIndex*2+1].id){
				return this;
			}
			if (heapArray[currentIndex].id == heapArray[currentIndex*2+1].id
				&& heapArray[currentIndex].enqOrder < heapArray[currentIndex*2+1].enqOrder){
				return this;
			}
			SwapNode(heapArray+currentIndex, heapArray+(currentIndex*2+1));
			return this;
		}

		//When the current node has both left and right children.
		////When there is no need to any swapping
		if (heapArray[currentIndex].id < heapArray[currentIndex*2+1].id
			&& heapArray[currentIndex].id < heapArray[currentIndex*2+2].id){
			return this;
		}

		////When there exists at least one child node whose id is smaller or equal to current node.
		if (heapArray[currentIndex*2+1].id < heapArray[currentIndex*2+2].id){
			if (heapArray[currentIndex].id == heapArray[currentIndex*2+1].id
				&& heapArray[currentIndex].enqOrder < heapArray[currentIndex*2+1].enqOrder){
				return this;
			}
			SwapNode(heapArray+currentIndex, heapArray+(currentIndex*2+1));
			currentIndex = currentIndex*2+1;
			continue;
		}

		if (heapArray[currentIndex*2+1].id > heapArray[currentIndex*2+2].id){
			if (heapArray[currentIndex].id == heapArray[currentIndex*2+2].id
				&& heapArray[currentIndex].enqOrder < heapArray[currentIndex*2+2].enqOrder){
				return this;
			}
			SwapNode(heapArray+currentIndex, heapArray+(currentIndex*2+2));
			currentIndex = currentIndex*2+2;
			continue;
		}

		if (heapArray[currentIndex*2+1].enqOrder < heapArray[currentIndex*2+2].enqOrder){
			if (heapArray[currentIndex].id == heapArray[currentIndex*2+1].id
				&& heapArray[currentIndex].enqOrder < heapArray[currentIndex*2+1].enqOrder){
				return this;
			}
			SwapNode(heapArray+currentIndex, heapArray+(currentIndex*2+1));
			currentIndex = currentIndex*2+1;
			continue;
		}

		if (heapArray[currentIndex*2+1].enqOrder > heapArray[currentIndex*2+2].enqOrder){
			if (heapArray[currentIndex].id == heapArray[currentIndex*2+2].id
				&& heapArray[currentIndex].enqOrder < heapArray[currentIndex*2+2].enqOrder){
				return this;
			}
			SwapNode(heapArray+currentIndex, heapArray+(currentIndex*2+2));
			currentIndex = currentIndex*2+2;
			continue;
		}

		//Exception Handling
		DEBUG << "ERROR: Unexpected Situation Occured." << std::endl;
		return NULL;
	}
	DEBUG << "ERROR: Unexpected Situation Occured." << std::endl;
	return NULL;
}

//Function Definitions
int SwapNode(HEAP_NODE *nodeA, HEAP_NODE *nodeB)
{
	char stringBuffer[STRING_LEN] = {0,};
	//Exception Handling1
	if (nodeA == NULL){
		DEBUG << "ERROR: nodeA is NULL." << std::endl;
		return -1;
	}

	//Exception Handling2
	if (nodeB == NULL){
		DEBUG << "ERROR: nodeB is NULL." << std::endl;
		return -2;
	}

	//id value swapping using XOR
	nodeA->id = (nodeA->id) ^ (nodeB->id);
	nodeB->id = (nodeA->id) ^ (nodeB->id);
	nodeA->id = (nodeA->id) ^ (nodeB->id);

	//data value swapping
	strncpy(stringBuffer, nodeA->data, STRING_LEN);
	strncpy(nodeA->data, nodeB->data, STRING_LEN);
	strncpy(nodeB->data, stringBuffer, STRING_LEN);

	//enqOrder value swapping using XOR
	nodeA->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);
	nodeB->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);
	nodeA->enqOrder = (nodeA->enqOrder) ^ (nodeB->enqOrder);

	return 0;
}
