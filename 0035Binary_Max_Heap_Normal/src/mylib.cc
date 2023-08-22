#include "mylib.h"

//Function Definitions
MAX_HEAP *CreateHeap(int level)
{
	MAX_HEAP *ret = NULL;
	try{
		ret = new MAX_HEAP;
	} catch (const std::bad_alloc& e) {
		std::cout << DEBUG << "ERROR: Memory Alloc Failed: " << e.what() << std::endl;
		return NULL;
	}

	int number_of_nodes = 1;

	//Exception Handling
	if (level <1){
		std::cout << DEBUG << "ERROR: level value is smaller than 1." << std::endl; 
		return NULL;
	}

	for (int i=0 ; i<level ; i++)
		number_of_nodes = number_of_nodes*2;

	number_of_nodes--;

	try{
		ret->heapArray = new HEAP_NODE[number_of_nodes];
	} catch (const std::bad_alloc& e) {
		std::cout << DEBUG << "ERROR: Memory Alloc Failed: " << e.what() << std::endl;
		return NULL;
	}

	ret->depth = level-1; 
	ret->maxNum = number_of_nodes;
	ret->lastIndex = -1; //set the status to empty.

	return ret;
}

int DeleteHeap(MAX_HEAP *heapArg)
{
	//Exception Handling1
	if (heapArg==NULL){
		std::cout << DEBUG << "ERROR: heapArg is NULL." << std::endl;
		return -1;
	}

	//Exception Handling2
	if (heapArg->heapArray==NULL){
		std::cout << DEBUG << "ERROR: heapArg->heapArray is NULL." << std::endl;
		return -2;
	}

	delete[] heapArg->heapArray;
	delete heapArg;

	return 0;
}

int SwapNode(HEAP_NODE *argA, HEAP_NODE *argB)
{
	//Exception Handling1
	if (argA == NULL){
		std::cout << DEBUG << "ERROR: argA is NULL.\n" << std::endl;
		return -1;
	}

	//Exception Handling2
	if (argB == NULL){
		std::cout << DEBUG << "ERROR: argB is NULL.\n" << std::endl;
		return -2;
	}

	//Swapping the key value.
	argA->key = (argA->key) ^ (argB->key);
	argB->key = (argA->key) ^ (argB->key);
	argA->key = (argA->key) ^ (argB->key);

	//Swapping the data value.
	for (int i=0 ; i<STRING_LEN ; i++){
		(argA->data)[i] = (argA->data)[i] ^ (argB->data)[i];
		(argB->data)[i] = (argA->data)[i] ^ (argB->data)[i];
		(argA->data)[i] = (argA->data)[i] ^ (argB->data)[i];
	}

	return 0;
}

MAX_HEAP *Insert(MAX_HEAP *heapArg, int keyArg, const char *dataArg)
{
	unsigned int currentIndex = 0;
	unsigned int parentIndex = 0;
	HEAP_NODE *tempArray = NULL;

	//Exception Handling1
	if (heapArg == NULL){
		std::cout << DEBUG << "ERROR: heapArg is NULL.\n" << std::endl;
		return NULL;
	}

	//Exception Handling2: When the Heap is full
	if (heapArg->lastIndex == heapArg->maxNum - 1){
		std::cout << DEBUG << "ERROR: heap is full currently.\n" << std::endl;
		return NULL;
	}
	
	tempArray = heapArg->heapArray;
	heapArg->lastIndex ++;
	
	currentIndex = heapArg->lastIndex;
	tempArray[currentIndex].key = keyArg;
	strncpy(tempArray->data, dataArg, STRING_LEN);
	
	while(1){
		//When the current node is a root node -> return.
		if (currentIndex==0)
			return heapArg;

		parentIndex = (currentIndex - 1) / 2;

		//When the parent node's key value is samller than the current node's key value -> Swap is needed.
		if (tempArray[parentIndex].key < tempArray[currentIndex].key){
			SwapNode(tempArray+parentIndex, tempArray+currentIndex);
			currentIndex = parentIndex;
			continue;
		}

		//When the swap is not needed -> return.
		return heapArg;
	}

	//Exception Handling3
	std::cout << DEBUG << "ERROR: Unexpected situation occured." << std::endl;
	return NULL;
}

MAX_HEAP *Delete(MAX_HEAP *heapArg, HEAP_NODE *outputStore)
{
	HEAP_NODE *tempArray = NULL;
	int currentIndex = 0;

	//Exception Handling1
	if (heapArg == NULL){
		std::cout << DEBUG << "ERROR: heapArg is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling2
	if (outputStore == NULL){
		std::cout << DEBUG << "ERROR: outputStore is NULL." << std::endl;
		return NULL;
	}

	//Exception Handling3: When the heap is empty.
	if (heapArg->lastIndex == -1){
		std::cout << DEBUG << "ERROR: Heap is empty currently." << std::endl;
		return NULL;
	}

	//Getting the root node's data
	tempArray = heapArg->heapArray;
	outputStore->key = tempArray[0].key;
	strncpy(outputStore->data, tempArray[0].data, STRING_LEN);	
	
	//When the last node of the heap is a root node
	if (heapArg->lastIndex == 0){
		heapArg->lastIndex = -1;
		return heapArg;
	}

	//Copying the last node's value to root node
	tempArray[0].key = tempArray[heapArg->lastIndex].key;
	strncpy(tempArray[0].data, tempArray[heapArg->lastIndex].data, STRING_LEN);

	//Deleting the former last node.
	heapArg->lastIndex -= 1;

	//Iterative Sapping
	//currentIndex is 0 currently.
	while(1){
		//When the current node is a leaf node.
		if (currentIndex*2 + 1 > heapArg->lastIndex)
			return heapArg;

		//When the current node has only a left child.
		if (currentIndex*2 + 1 == heapArg->lastIndex){
			if (tempArray[currentIndex].key >= tempArray[currentIndex*2 + 1].key)
				return heapArg;

			SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2 + 1));
			return heapArg;
		}

		//When the current node has both left and right children.
		if((tempArray[currentIndex].key >= tempArray[currentIndex*2 + 1].key) 
			&& (tempArray[currentIndex].key >= tempArray[currentIndex*2 + 2].key)){
			return heapArg;
			}
		
		//When there is at least one child node whose key value is bigger than current node's key value.
		if(tempArray[currentIndex*2 + 1].key > tempArray[currentIndex*2 + 2].key){
			SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2 + 1));
			currentIndex = currentIndex*2 + 1;
			continue;
		}

		if(tempArray[currentIndex*2 + 1].key <= tempArray[currentIndex*2 + 2].key){
			SwapNode(tempArray+currentIndex, tempArray+(currentIndex*2 + 2));
			currentIndex = currentIndex*2 + 2;
			continue;
		}

		//Exception Handling
		std::cout << DEBUG << "ERROR: Unexpected situation occurs." << std::endl;
	}

	return NULL;
}



































