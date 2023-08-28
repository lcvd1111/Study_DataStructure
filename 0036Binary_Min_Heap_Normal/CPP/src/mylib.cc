#include "mylib.hh"

//Function and Method Definitions

HEAP *CreateHeap(int levelArg)
{
	HEAP *ret = new HEAP;

	//Exception Handling
	if (ret==NULL){
		std::cout << DEBUG << "ERROR: new HEAP failed." << std::endl;
		return NULL;
	}

	ret->level = levelArg;
	ret->size = 1;
	for (int i=0 ; i<levelArg ; i++)
		ret->size = 2*(ret->size);
	ret->size -= 1;
	
	ret->heapArray = new HEAP_NODE[ret->size];
	//Exception Handling
	if (ret->heapArray == NULL){
		std::cout << DEBUG << "ERROR: new HEAP_NODE[] failed." << std::endl;
		return NULL;
	}

	ret->lastIndex = -1; //Setting the initial status to 'Empty Status'

	return ret;
}

int DestroyHeap(HEAP *heapArg)
{
	//Exception Handling
	if (heapArg==NULL){
		std::cout << DEBUG << "ERROR: heapArg is NULL." << std::endl;
		return -1;
	}

	//Exception Handling2
	if (heapArg->heapArray == NULL){
		std::cout << DEBUG << "ERROR: heapArg->heapArray is NULL." << std::endl;
		return -2;
	}


	delete[] heapArg->heapArray;
	delete heapArg;

	return 0;
}

int SwapNode(HEAP_NODE *nodeA, HEAP_NODE *nodeB)
{
	char stringBuffer[STRING_LEN] = {0,};

	//Exception Handling1
	if (nodeA==NULL){
		std::cout << DEBUG << "ERROR: nodeA is NULL." << std::endl;
		return -1;
	}

	//Exception Handling2
	if (nodeB == NULL){
		std::cout << DEBUG << "ERROR: nodeB is NULL." << std::endl;
		return -2;
	}

	nodeA->id = (nodeA->id) ^ (nodeB->id);
	nodeB->id = (nodeA->id) ^ (nodeB->id);
	nodeA->id = (nodeA->id) ^ (nodeB->id);
	
	strncpy(stringBuffer, nodeA->data, STRING_LEN);
	strncpy(nodeA->data, nodeB->data, STRING_LEN);
	strncpy(nodeB->data, stringBuffer, STRING_LEN);

	return 0;
}


HEAP *HEAP::Enqueue(int idArg, const char *dataArg)
{
	long int currentIndex = 0;

	//Exception Handling1
	if (this==NULL){
		std::cout << "ERROR: 'object itself' is NULL" << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (this->heapArray == NULL){
		std::cout << "ERROR: Member variable heapArray is NULL." << std::endl;
		return NULL;
	}

	//When the heap is full currently.
	if (lastIndex+1 == size)
		return NULL;

	//Increasing the number of memebers and fill the last node with input data.
	lastIndex++;
	heapArray[lastIndex].id = idArg;
	strncpy(heapArray[lastIndex].data, dataArg, STRING_LEN);
	
	//Iterative Swapping
	currentIndex = lastIndex;

	while (1){
		//When the current node is a root node.
		if (currentIndex == 0)
			return this;

		//When the Swapping is not needed.
		if (heapArray[currentIndex].id >= heapArray[(currentIndex-1)/2].id)
			return this;

		//When the Swapping is needed.
		SwapNode(heapArray+currentIndex, heapArray+((currentIndex-1)/2));
		currentIndex = (currentIndex-1)/2;
		continue;
	}

	//Exception Handling.
	std::cout << DEBUG << "ERROR: Unexpected sitaution occured." << std::endl;
	return NULL;
}


HEAP *HEAP::Dequeue(HEAP_NODE *outputStore)
{
	long int currentIndex = 0;

	//Exception Handling
	if (this == NULL){
		std::cout << DEBUG << "ERROR: 'object itself' is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (heapArray == NULL){
		std::cout << DEBUG << "Member variabel heapArray is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling3
	if (outputStore == NULL){
		std::cout << DEBUG << "outputStore is NULL." << std::endl;
		return NULL;
	}

	//When the heap is empty currently.
	if (lastIndex == -1)
		return NULL;

	//Copying the root node's data to outputStorage.
	outputStore->id = heapArray[0].id;
	strncpy(outputStore->data, heapArray[0].data, STRING_LEN);

	//When the heap becomes empty after the dequeueing.
	if (lastIndex == 0){
		lastIndex -= 1;
		return this;
	}

	//Copying the last node's data to root node.
	heapArray[0].id = heapArray[lastIndex].id;
	strncpy(heapArray[0].data, heapArray[lastIndex].data, STRING_LEN);

	lastIndex -= 1;

	//Iterative Swapping. currentIndex is 0 currently.
	while(1){
		//When the current node doesn't have any children at all.
		if (currentIndex*2 + 1 > lastIndex)
			return this;

		//When the current node has only a left child.
		////In this case, left child is the last node of the heap.
		if (currentIndex*2 + 1 == lastIndex){
			if (heapArray[currentIndex].id > heapArray[currentIndex*2 + 1].id){
				SwapNode(heapArray+currentIndex, heapArray+(2*currentIndex + 1));
				return this;
			}
			return this;
		}

		//When the current node has both left and right children.
		////When the swap is not needed
		if (heapArray[currentIndex].id <= heapArray[currentIndex*2 + 1].id
			&& heapArray[currentIndex].id <= heapArray[currentIndex*2 + 2].id)
			return this;

		////When the swap is needed
		if (heapArray[currentIndex*2 + 1].id < heapArray[currentIndex*2 + 2].id){
			SwapNode(heapArray+currentIndex, heapArray+(currentIndex*2 + 1));
			currentIndex = currentIndex*2 + 1;
			continue;
		}
		else {
			SwapNode(heapArray+currentIndex, heapArray+(currentIndex*2 + 2));
			currentIndex = currentIndex*2 + 2;
			continue;
		}

		//Exception Handling
		std::cout << DEBUG << "ERROR: Unexpected situation occured." << std::endl;
		return NULL;
	}
	
	return NULL;
}
